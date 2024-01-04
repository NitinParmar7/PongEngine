#pragma once
#include <SFML/Graphics/Rect.hpp>
#include "CollisionDef.h"
#include "PongEngine.h"
#include "../../CoreTypeDef.h"
#include "../core/GameObjectComponent.h"

ENGINE_BEGIN

class CollisionComponent : public GameObjectComponent
{
public:

    CollisionComponent(const CollisionComponent& other) = default;

    CollisionComponent(CollisionComponent&& other) noexcept
        : GameObjectComponent(std::move(other)),
          collision_profile_(other.collision_profile_)
    {
    }

    CollisionComponent& operator=(const CollisionComponent& other)
    {
        if (this == &other)
            return *this;
        GameObjectComponent::operator =(other);
        collision_profile_ = other.collision_profile_;
        return *this;
    }

    CollisionComponent& operator=(CollisionComponent&& other) noexcept
    {
        if (this == &other)
            return *this;
        GameObjectComponent::operator =(std::move(other));
        collision_profile_ = other.collision_profile_;
        return *this;
    }

    ~CollisionComponent() override;

    CollisionComponent()
        : collision_profile_(ECOLLISION_PROFILE::No_Collision) {};

    explicit CollisionComponent(const ECOLLISION_PROFILE profile)
        : collision_profile_(profile)
    {
        ENGINE.GetCollisionHandler()->AddComponent(std::shared_ptr<CollisionComponent>(this));
    }

    [[nodiscard]] virtual  sf::FloatRect GetGlobalBounds() const = 0;

    [[nodiscard]] virtual ECOLLISION_PROFILE GetCollisionProfile() const {return collision_profile_;}


private:

    ECOLLISION_PROFILE collision_profile_;
};

ENGINE_END
