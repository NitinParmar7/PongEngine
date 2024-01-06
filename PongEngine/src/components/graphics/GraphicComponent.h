#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../src/CoreTypeDef.h"
#include "DrawableEntity.h"
#include "../core/GameObjectComponent.h"
#include "components/core/ListableGameObjectComponent.h"


ENGINE_BEGIN
class GraphicComponent : public ListableGameObjectComponent
{
public:

    virtual void draw(std::shared_ptr<sf::RenderWindow>& window) const = 0;

    [[nodiscard]] virtual std::shared_ptr<DrawableEntity> GetDrawableEntity() const = 0;

};


ENGINE_END