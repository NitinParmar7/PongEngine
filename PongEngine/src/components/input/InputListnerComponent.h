#pragma once
#include <SFML/Graphics.hpp>

#include "CoreTypeDef.h"

ENGINE_BEGIN

class InputListenerComponent
{
public:

    sf::Keyboard::Key key;

    void OnClick();

};

ENGINE_END