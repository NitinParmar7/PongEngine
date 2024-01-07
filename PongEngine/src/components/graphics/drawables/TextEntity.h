#pragma once
#include <SFML/Graphics/Font.hpp>

#include "CoreTypeDef.h"
#include "components/graphics/core/DrawableEntity.h"

ENGINE_BEGIN
class TextEntity : public DrawableEntity
{
public:

    TextEntity();

private:

    sf::Font m_open_sans;
};

ENGINE_END
