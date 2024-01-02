#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "CoreTypeDef.h"
#include "core/ListableEngineComponent.h"


ENGINE_BEGIN
    class RenderComponent : ListableEngineComponent
{
public:
    void init(const EngineCore* parent) override;
    void update() override;
    void end() override;

    virtual void Draw(std::shared_ptr<sf::RenderWindow>& window) const;
};

ENGINE_END
