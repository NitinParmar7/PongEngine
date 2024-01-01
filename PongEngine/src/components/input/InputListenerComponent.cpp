#include "InputListenerComponent.h"

ENGINE_BEGIN

    void InputListenerComponent::OnClick()
    {
        pressed_ = true;
    }

    void InputListenerComponent::ConsumeInput()
    {
        pressed_ = false;
    }

ENGINE_END
