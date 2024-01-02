﻿
#include "InputComponent.h"

#include <SFML/Window/Keyboard.hpp>

#include "InputListenerComponent.h"


ENGINE_BEGIN
    void InputComponent::init(const EngineCore* parent)
    {
        ListableEngineComponent::init(parent);
    }

    void InputComponent::update()
    {
        for (auto& element : components_)
        {
            if(const auto input_component = std::dynamic_pointer_cast<InputListenerComponent>(element))
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


ENGINE_END
