#include "TitleGameObject.h"

#include "components/graphics/core/GraphicComponent.h"
#include "core/Helper.h"

TitleGameObject::TitleGameObject()
{
    GE::Helper::AddObject<GE::GraphicComponent, GE::ListableGameObjectComponent>(m_game_object_components);
}
