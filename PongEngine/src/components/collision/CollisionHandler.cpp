#include "CollisionHandler.h"

ENGINE_BEGIN

CollisionHandler::CollisionHandler(const CollisionHandler& other) = default;

CollisionHandler::CollisionHandler(CollisionHandler&& other) noexcept: ListableEngineComponent(other)
{
}

CollisionHandler& GE::CollisionHandler::operator=(const CollisionHandler& other)
{
    if (this == &other)
        return *this;
    ListableEngineComponent::operator =(other);
    return *this;
}

CollisionHandler& GE::CollisionHandler::operator=(CollisionHandler&& other) noexcept
{
    if (this == &other)
        return *this;
    ListableEngineComponent::operator =(other);
    return *this;
}

CollisionHandler::~CollisionHandler() = default;

void CollisionHandler::update()
{
    ListableEngineComponent::update();
    
}


ENGINE_END
