#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <string>

ENGINE_BEGIN

    EngineCore& EngineCore::get()
    {
        static std::unique_ptr<EngineCore> instance(new EngineCore());
        return *instance;
    }

    void EngineCore::init(unsigned int width_to_set, unsigned int height_to_set, std::string_view title_to_set)
    {
        width_ = width_to_set;
        height_ = height_to_set;
        title_ = title_to_set;
        start();
    }

    void EngineCore::start()
    {
        sf::RenderWindow window(sf::VideoMode(width_, height_), static_cast<std::string>(title_));
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }
    }

ENGINE_END

