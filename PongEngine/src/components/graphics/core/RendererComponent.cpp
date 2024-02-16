﻿#include "RendererComponent.h"

#include "DrawableComponent.h"

namespace GE {
    RendererComponent::RendererComponent(const EngineCore* parent): ListableEngineComponent(parent)
    {
    }

    void RendererComponent::init(const EngineCore* parent)
    {
        ListableEngineComponent::init(parent);
    }

    void RendererComponent::update()
    {
        ListableEngineComponent::update();
    }

    void RendererComponent::end()
    {
        ListableEngineComponent::end();
    }


    void RendererComponent::Draw(std::shared_ptr<sf::RenderWindow>& window) const
    {
        for (const auto& element : m_components_)
        {
            if (const auto graphic_component = std::dynamic_pointer_cast<DrawableComponent>(element))
            {
                graphic_component->draw(window);
            }
        }
    }

}
