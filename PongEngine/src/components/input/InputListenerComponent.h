#pragma once
#include <SFML/Graphics.hpp>
#include "CoreTypeDef.h"

ENGINE_BEGIN

typedef sf::Keyboard::Key Key;


class InputListenerComponent
{
public:


    InputListenerComponent()
        : key_(Key::Unknown) {}

    explicit InputListenerComponent(const Key key)
        : key_(key) {}

    void OnClick();

    [[nodiscard]] bool IsPressed() const { return pressed_; }

    void ConsumeInput();

private:

    bool pressed_ = false;

    sf::Keyboard::Key key_;

};

ENGINE_END