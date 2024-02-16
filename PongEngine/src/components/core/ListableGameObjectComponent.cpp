#include "ListableGameObjectComponent.h"

#include "ListableEngineComponent.h"

namespace GE {
    ListableGameObjectComponent::ListableGameObjectComponent(
        const std::shared_ptr<ListableEngineComponent>& engine_component): GameObjectComponent()
    {
        m_engine_component = engine_component;
        m_engine_component->AddComponent(LComponent(this));
    }

    ListableGameObjectComponent::~ListableGameObjectComponent()
    {
        m_engine_component->RemoveComponent(LComponent(this));
    }

}
