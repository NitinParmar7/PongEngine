#include "TextEntity.h"

ENGINE_BEGIN

TextEntity::TextEntity(): DrawableEntity()
{
    m_open_sans.loadFromFile("PongEngine/resources/font/open_sans/static/OpenSans-Regular.ttf");
}


ENGINE_END
