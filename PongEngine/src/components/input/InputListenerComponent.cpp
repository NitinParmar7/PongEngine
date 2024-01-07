#include "InputListenerComponent.h"

ENGINE_BEGIN
    void InputListenerComponent::update()
    {
    }

    void InputListenerComponent::end()
    {
    }

    void InputListenerComponent::init(const GameObject* parent)
    {
        GameObjectComponent::init(parent);
    }

    InputListenerComponent::~InputListenerComponent()
    {
        pressed_ = false;
    }

    void InputListenerComponent::OnClick()
    {
        pressed_ = true;
    }

    void InputListenerComponent::ConsumeInput()
    {
        pressed_ = false;
    }

ENGINE_END
