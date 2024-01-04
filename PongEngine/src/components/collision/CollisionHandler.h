#pragma once
#include "../../CoreTypeDef.h"
#include "../core/ListableEngineComponent.h"

ENGINE_BEGIN
class CollisionHandler : public ListableEngineComponent
{
public:
    CollisionHandler(const CollisionHandler& other);

    CollisionHandler(CollisionHandler&& other) noexcept;

    CollisionHandler& operator=(const CollisionHandler& other);

    CollisionHandler& operator=(CollisionHandler&& other) noexcept;

    ~CollisionHandler() override;

#pragma region EngineComponent

    void update() override;

#pragma endregion
};

ENGINE_END
