#pragma once
#include <utility>

#include "BaseComponent.h"


namespace GE {
    class GameObject;

    class GameObjectComponent : public BaseComponent
    {
    public:
        GameObjectComponent(const GameObjectComponent& other);

        GameObjectComponent(GameObjectComponent&& other) noexcept;

        GameObjectComponent() = default;

        GameObjectComponent& operator=(const GameObjectComponent& other);

        GameObjectComponent& operator=(GameObjectComponent&& other) noexcept;


        virtual void init(const GameObject* parent);

#pragma region BaseComponent
        void update() override;
        void end() override;
        ~GameObjectComponent() override;
#pragma endregion
    };

}
