﻿#pragma once
#include "CollisionDef.h"
#include "../../CoreTypeDef.h"
#include "../core/ListableEngineComponent.h"

ENGINE_BEGIN
    class CollisionComponent;


typedef std::vector<std::shared_ptr<CollisionComponent>> Components;

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

    void CopyCollisionComponents(Components& components, ECOLLISION_PROFILE profile);

    static void CheckOnHit(const Components& components);

    static void CheckOverlaps(const Components& hit_component, const Components& overlap_components);

private:

    int m_prev_array_size {0};

    Components m_hitting_collision_components;

    Components m_overlapping_collision_components;
};

ENGINE_END
