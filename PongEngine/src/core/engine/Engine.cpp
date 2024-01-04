#include "Engine.h"

#include <string>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

#include "../../components/graphics/RendererComponent.h"
#include "../../components/input/InputComponent.h"
#include "../../components/scene/SceneManager.h"


ENGINE_BEGIN
    EngineCore& EngineCore::get()
    {
        static std::unique_ptr<EngineCore> instance(new EngineCore());
        return *instance;
    }

    template <class T>
    std::shared_ptr<T> EngineCore::CreateComponent()
    {
        auto ptr = std::make_shared<T>();
        engine_components_.emplace_back(ptr);
        return std::static_pointer_cast<T>(engine_components_.back());
    }

    void EngineCore::init(unsigned int width_to_set, unsigned int height_to_set, std::string_view title_to_set)
    {
        data_ =  std::make_shared<EngineData>(width_to_set, height_to_set, title_to_set);
        render_window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(data_->WIDTH, data_->HEIGHT), static_cast<std::string>(data_->TITLE));
        scene_manager_ =  CreateComponent<SceneManager>();
        input_component_ = CreateComponent<InputComponent>();
        renderer_component_ = CreateComponent<RendererComponent>();
        run();
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    void EngineCore::run()
    {
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        for (auto& element : engine_components_)
        {
            element->init(this);
        }
        while (render_window_->isOpen())
        {
            sf::Event event;
            while (render_window_->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    render_window_->close();
            }

            render_window_->clear();

            for (auto& element : engine_components_)
            {
                element->update();
            }
            render_window_->draw(shape);
            renderer_component_->Draw(render_window_);
            render_window_->display();
            scene_manager_->ProcessScene();
        }

        for (auto& element : engine_components_)
        {
            element->end();
        }

    }

    std::shared_ptr<EngineData> EngineCore::GetData() const
    { return data_; }

    std::shared_ptr<CollisionHandler> EngineCore::GetCollisionHandler() const
    { return collision_handler_; }

    std::shared_ptr<sf::RenderWindow> EngineCore::GetRenderWindow() const
    { 	return render_window_; 	}

    std::shared_ptr<InputComponent> EngineCore::GetInputComponent() const
    {
        return input_component_;
    }

    std::shared_ptr<RendererComponent> EngineCore::GetRendererComponent() const
    {
        return renderer_component_;
    }

    std::shared_ptr<CollisionHandler> EngineCore::collision_handler() const
    {
        return collision_handler_;
    }

    std::vector<std::shared_ptr<EngineComponent>> EngineCore::GetEngineComponents() const
    {
        return engine_components_;
    }

    std::shared_ptr<SceneManager> EngineCore::GetSceneManager() const
    {
        return scene_manager_;
    }


ENGINE_END

