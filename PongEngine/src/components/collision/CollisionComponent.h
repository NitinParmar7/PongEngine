#pragma once
#include <SFML/Graphics/Rect.hpp>
#include "CollisionDef.h"
#include "PongEngine.h"
#include "../../CoreTypeDef.h"
#include "../core/GameObjectComponent.h"
#include "components/core/ListableGameObjectComponent.h"

ENGINE_BEGIN
    class CollisionComponent : public ListableGameObjectComponent
    {
    public:
        CollisionComponent(const CollisionComponent& other);

        CollisionComponent(CollisionComponent&& other) noexcept;

        CollisionComponent& operator=(const CollisionComponent& other);

        CollisionComponent& operator=(CollisionComponent&& other) noexcept;

        ~CollisionComponent() override;

        CollisionComponent();;

        explicit CollisionComponent(const std::shared_ptr<ListableEngineComponent>& engine_component,
                                    ECOLLISION_PROFILE profile);

        explicit CollisionComponent(const std::shared_ptr<ListableEngineComponent>& engine_component,
                                    ECOLLISION_PROFILE profile, const std::shared_ptr<sf::Shape>& shared_ptr);


        [[nodiscard]] virtual sf::FloatRect GetGlobalBounds() const;

        [[nodiscard]] virtual ECOLLISION_PROFILE GetCollisionProfile() const;

        virtual void OnHit(const std::shared_ptr<CollisionComponent>& other);

        virtual void OnOverlap(const std::shared_ptr<CollisionComponent>& other);

    private:
        ECOLLISION_PROFILE m_collision_profile_;

        std::shared_ptr<sf::Shape> m_shape_bounds;
    };

ENGINE_END
