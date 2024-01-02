#include "Engine.h"

#include <string>

#include "../components/scene/SceneManager.h"
#include "input/InputComponent.h"


ENGINE_BEGIN
    EngineCore& EngineCore::get()
    {
        static std::unique_ptr<EngineCore> instance(new EngineCore());
        return *instance;
    }

    template <class T>
    std::unique_ptr<T> EngineCore::CreateComponent(T* component)
    {
        auto ptr = std::make_unique<T>(component);
        return engine_components_.emplace_back(std::move(ptr));
    }

    void EngineCore::init(unsigned int width_to_set, unsigned int height_to_set, std::string_view title_to_set)
    {
        data_ =  std::make_shared<EngineData>(width_to_set, height_to_set, title_to_set);
        render_window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(data_->WIDTH, data_->HEIGHT), static_cast<std::string>(data_->TITLE));
        scene_manager_ = CreateComponent(new SceneManager());
        input_component_ = CreateComponent(new InputComponent());
        render_component_ = CreateComponent(new RenderComponent());
        run();
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    void EngineCore::run()
    {
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        for (auto element& : engine_components_)
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

            for (auto element& : engine_components_)
            {
                element->update();
            }
            render_window_->draw(shape);
            render_component_->Draw(render_window_);
            render_window_->display();
            scene_manager_->ProcessScene();
        }

        for (auto element& : engine_components_)
        {
            element->end();
        }

    }


ENGINE_END

