#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../core/ListableGameObjectComponent.h"


namespace GE {

    class DrawableComponent : public ListableGameObjectComponent
    {
    public:
        virtual void draw(std::shared_ptr<sf::RenderWindow>& window) const = 0;

    };


}
