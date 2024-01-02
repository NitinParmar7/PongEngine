#include "EngineComponent.h"

ENGINE_BEGIN
    EngineComponent::~EngineComponent()
    {
    parent_ = nullptr;
    }

void EngineComponent::init(const EngineCore* parent)
{
    parent_ = parent;
}

ENGINE_END
