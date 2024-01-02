#include "RenderComponent.h"

#include "GraphicComponent.h"

ENGINE_BEGIN
    void RenderComponent::init(const EngineCore* parent)
    {
        ListableEngineComponent::init(parent);
    }

    void RenderComponent::update()
    {
        ListableEngineComponent::update();
    }

    void RenderComponent::end()
    {
        ListableEngineComponent::end();
    }

    void RenderComponent::Draw(std::shared_ptr<sf::RenderWindow>& window) const
    {
    for (auto element& : components_)
    {
        if(const auto graphic_component = std::dynamic_pointer_cast<GraphicComponent>(element))
        {
            graphic_component->draw(window);
        }
        
    }
}

ENGINE_END
