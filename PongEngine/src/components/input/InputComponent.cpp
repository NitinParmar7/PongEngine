
#include "InputComponent.h"

#include <SFML/Window/Keyboard.hpp>

#include "InputListenerComponent.h"


ENGINE_BEGIN
    void InputComponent::update()
    {
        for (const auto& element : input_listener_components_)
        {
            if (sf::Keyboard::isKeyPressed(element->GetKey()))
            {
                element->OnClick();
            }
        }
    }

    void InputComponent::AddInputListenerComponent(
        const TypeInputListenerComponent& input_listener_component)
    {
        input_listener_components_.emplace_back(input_listener_component);
    }

    bool InputComponent::RemoveInputListenerComponent(
        const TypeInputListenerComponent& input_listener_component)
    {
        return std::erase(input_listener_components_, input_listener_component);
    }


ENGINE_END
