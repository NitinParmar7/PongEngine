#include "Engine.h"

#include <string>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include "../../components/graphics/core/RendererComponent.h"
#include "../../components/input/InputComponent.h"
#include "../../components/scene/SceneManager.h"


ENGINE_BEGIN
    template <class T>
    std::shared_ptr<T> EngineCore::CreateComponent()
    {
        auto ptr = std::make_shared<T>(this);
        m_engine_components_.emplace_back(ptr);
        return std::static_pointer_cast<T>(m_engine_components_.back());
    }


    void EngineCore::init()
    {
        m_data_ = GetData();
        m_render_window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(m_data_->WIDTH, m_data_->HEIGHT),
                                                              static_cast<std::string>(m_data_->TITLE));
        m_scene_manager_ = CreateComponent<SceneManager>();
        m_input_component_ = CreateComponent<InputComponent>();
        m_renderer_component_ = CreateComponent<RendererComponent>();
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    void EngineCore::run()
    {
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        for (auto& element : m_engine_components_)
        {
            element->init(this);
        }
        while (m_render_window_->isOpen())
        {
            sf::Event event;
            while (m_render_window_->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_render_window_->close();
            }

            m_render_window_->clear();

            for (auto& element : m_engine_components_)
            {
                element->update();
            }
            m_render_window_->draw(shape);
            m_renderer_component_->Draw(m_render_window_);
            m_render_window_->display();
            m_scene_manager_->ProcessScene();
        }

        for (auto& element : m_engine_components_)
        {
            element->end();
        }
    }

    void EngineCore::exit()
    {
        m_collision_handler_.reset();
        m_render_window_.reset();
        m_input_component_.reset();
        m_renderer_component_.reset();
        m_scene_manager_.reset();
        m_engine_components_.clear();
    }

    std::shared_ptr<EngineData> EngineCore::GetData() const
    {
        return std::make_shared<EngineData>();
    }

    std::shared_ptr<CollisionHandler> EngineCore::GetCollisionHandler() const
    {
        return m_collision_handler_;
    }

    std::shared_ptr<sf::RenderWindow> EngineCore::GetRenderWindow() const
    {
        return m_render_window_;
    }

    std::shared_ptr<InputComponent> EngineCore::GetInputComponent() const
    {
        return m_input_component_;
    }

    std::shared_ptr<RendererComponent> EngineCore::GetRendererComponent() const
    {
        return m_renderer_component_;
    }

    std::vector<std::shared_ptr<EngineComponent>> EngineCore::GetEngineComponents() const
    {
        return m_engine_components_;
    }

    std::string_view EngineCore::GetTitle() const
    {
        return m_data_->TITLE;
    }

    unsigned EngineCore::GetWidth() const
    {
        return m_data_->WIDTH;
    }

    unsigned EngineCore::GetHeight() const
    {
        return m_data_->HEIGHT;
    }

    std::shared_ptr<SceneManager> EngineCore::GetSceneManager() const
    {
        return m_scene_manager_;
    }


ENGINE_END
