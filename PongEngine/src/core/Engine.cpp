#include "Engine.h"

#include <string>

#include "../components/scene/SceneManager.h"


ENGINE_BEGIN
    EngineCore& EngineCore::get()
    {
        static std::unique_ptr<EngineCore> instance(new EngineCore());
        return *instance;
    }

    void EngineCore::init(unsigned int width_to_set, unsigned int height_to_set, std::string_view title_to_set)
    {
        data_ =  std::make_shared<EngineData>(width_to_set, height_to_set, title_to_set);
        render_window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(data_->WIDTH, data_->HEIGHT), static_cast<std::string>(data_->TITLE));
        scene_manager_ = std::make_unique<SceneManager>();
        run();
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    void EngineCore::run()
    {
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (render_window_->isOpen())
        {
            sf::Event event;
            while (render_window_->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    render_window_->close();
            }

            render_window_->clear();
            render_window_->draw(shape);
            render_window_->display();
            scene_manager_->ProcessScene();
        }
    }

ENGINE_END

