#include "CollisionHandler.h"

#include <unordered_set>

#include "CollisionComponent.h"

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
        if (m_prev_array_size != m_components_.size())
        {
            CopyCollisionComponents(m_hitting_collision_components, ECOLLISION_PROFILE::Hit);
            CopyCollisionComponents(m_overlapping_collision_components, ECOLLISION_PROFILE::Overlap);
        }
        CheckOnHit(m_hitting_collision_components);
        CheckOverlaps(m_hitting_collision_components, m_overlapping_collision_components);
    }

    void CollisionHandler::CopyCollisionComponents(const Components& components, ECOLLISION_PROFILE profile)
    {
        components.empty();
        std::copy_if(m_components_.begin(), m_components_.end(), std::back_inserter(components),
                     [profile](const LComponent& ptr)
                     {
                         const std::shared_ptr<CollisionComponent> collision_component = std::dynamic_pointer_cast<
                             CollisionComponent>(ptr);
                         return collision_component != nullptr && collision_component->GetCollisionProfile() == profile;
                     });
    }

    void CollisionHandler::CheckOnHit(const Components& components)
    {
        for (size_t i = 0; i < components.size(); ++i)
        {
            for (size_t j = i + 1; j < components.size(); ++j)
            {
                const auto& rect1 = components[i]->GetGlobalBounds();
                if (const auto& rect2 = components[j]->GetGlobalBounds(); rect1.intersects(rect2))
                {
                    components[i]->OnHit(components[j]);
                    components[j]->OnHit(components[i]);
                }
            }
        }
    }

    void CollisionHandler::CheckOverlaps(const Components& hit_component, const Components& overlap_components)
    {
        // Handle overlaps between array1 and array2
        for (const auto& hit : hit_component)
        {
            const auto& rect1 = hit->GetGlobalBounds();

            for (const auto& overlap_component : overlap_components)
            {
                if (const auto& rect2 = overlap_component->GetGlobalBounds(); rect1.intersects(rect2)) {
                    hit->OnOverlap(overlap_component);
                    overlap_component->OnOverlap(hit);
                }
            }
        }

        for (size_t i = 0; i < overlap_components.size(); ++i)
        {
            for (size_t j = i + 1; j < overlap_components.size(); ++j)
            {
                const auto& rect1 = overlap_components[i]->GetGlobalBounds();
                if (const auto& rect2 = overlap_components[j]->GetGlobalBounds(); rect1.intersects(rect2))
                {
                    overlap_components[i]->OnOverlap(overlap_components[j]);
                    overlap_components[j]->OnOverlap(overlap_components[i]);
                }
            }
        }
    }


ENGINE_END
