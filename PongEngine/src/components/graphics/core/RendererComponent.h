#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "../../../CoreTypeDef.h"
#include "../../core/ListableEngineComponent.h"


ENGINE_BEGIN
    class RendererComponent : public ListableEngineComponent
{
public:

    explicit RendererComponent(const EngineCore* parent);

#pragma region EngineComponent

    void init(const EngineCore* parent) override;
    void update() override;
    void end() override;
#pragma endregion


    virtual void Draw( std::shared_ptr<sf::RenderWindow>& window) const;
};

ENGINE_END
