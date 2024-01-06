#include "CollisionComponent.h"


ENGINE_BEGIN
    CollisionComponent::CollisionComponent(const CollisionComponent& other): ListableGameObjectComponent(other),
                                                                             m_collision_profile_(
                                                                                 other.m_collision_profile_)
    {
    }

    CollisionComponent::CollisionComponent(CollisionComponent&& other) noexcept:
        ListableGameObjectComponent(other),
        m_collision_profile_(other.m_collision_profile_)
    {
    }

    CollisionComponent& CollisionComponent::operator=(const CollisionComponent& other)
    {
        if (this == &other)
            return *this;
        ListableGameObjectComponent::operator =(other);
        m_collision_profile_ = other.m_collision_profile_;
        return *this;
    }

    CollisionComponent& CollisionComponent::operator=(CollisionComponent&& other) noexcept
    {
        if (this == &other)
            return *this;
        ListableGameObjectComponent::operator =(other);
        m_collision_profile_ = other.m_collision_profile_;
        return *this;
    }


    CollisionComponent::CollisionComponent(): ListableGameObjectComponent(),
                                              m_collision_profile_(ECOLLISION_PROFILE::No_Collision),
                                              m_shape_bounds(nullptr)
    {
    }

    CollisionComponent::CollisionComponent(const std::shared_ptr<ListableEngineComponent>& engine_component,
                                           const ECOLLISION_PROFILE profile)
        : ListableGameObjectComponent(engine_component), m_collision_profile_(profile), m_shape_bounds(nullptr)
    {
    }

    CollisionComponent::CollisionComponent(const std::shared_ptr<ListableEngineComponent>& engine_component,
                                           const ECOLLISION_PROFILE profile,
                                           const std::shared_ptr<sf::Shape>& shared_ptr)
        : ListableGameObjectComponent(engine_component), m_collision_profile_(profile), m_shape_bounds(shared_ptr)
    {
    }

    ECOLLISION_PROFILE CollisionComponent::GetCollisionProfile() const
    {
        return m_collision_profile_;
    }

    void CollisionComponent::OnHit(const std::shared_ptr<CollisionComponent>& other)
    {
    }

    CollisionComponent::~CollisionComponent()
    = default;

    sf::FloatRect CollisionComponent::GetGlobalBounds() const
    {
        return m_shape_bounds->getGlobalBounds();
    }

ENGINE_END
