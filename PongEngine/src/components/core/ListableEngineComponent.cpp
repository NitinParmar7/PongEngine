#include "ListableEngineComponent.h"


ENGINE_BEGIN
    ListableEngineComponent::~ListableEngineComponent()
    {
        components_.clear();
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
        components_.emplace_back(component);
    }

    bool ListableEngineComponent::RemoveComponent(const LComponent& component)
    {
         return std::erase(components_, component);
    }

ENGINE_END
