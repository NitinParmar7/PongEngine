#include "InputComponent.h"

#include <SFML/Window/Keyboard.hpp>

#include "InputListenerComponent.h"


namespace GE {
    InputComponent::InputComponent(const EngineCore* parent): ListableEngineComponent(parent)
    {
    }

    void InputComponent::init(const EngineCore* parent)
    {
        ListableEngineComponent::init(parent);
    }

    void InputComponent::update()
    {
        for (auto& element : m_components_)
        {
            if (const auto input_component = std::dynamic_pointer_cast<InputListenerComponent>(element))
            {
                if (sf::Keyboard::isKeyPressed(input_component->GetKey()))
                {
                    input_component->OnClick();
                }
            }
        }
    }

    void InputComponent::end()
    {
        ListableEngineComponent::end();
    }


}
