#include "ListableEngineComponent.h"


ENGINE_BEGIN
    ListableEngineComponent::~ListableEngineComponent()
    {
        m_components_.clear();
    }

    void ListableEngineComponent::init(const EngineCore* parent)
    {
        EngineComponent::init(parent);
    }

    void ListableEngineComponent::update()
    {
    }

    void ListableEngineComponent::end()
    {
    }

    void ListableEngineComponent::AddComponent(const LComponent& component)
    {
        m_components_.emplace_back(component);
    }

    bool ListableEngineComponent::RemoveComponent(const LComponent& component)
    {
         return std::erase(m_components_, component);
    }

ENGINE_END
