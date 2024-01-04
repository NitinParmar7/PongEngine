#include "CollisionComponent.h"


ENGINE_BEGIN

CollisionComponent::~CollisionComponent()
{
    ENGINE.GetCollisionHandler()->RemoveComponent(std::shared_ptr<CollisionComponent>(this));
}

ENGINE_END
