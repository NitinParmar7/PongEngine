#pragma once
#include <utility>

#include "BaseComponent.h"


ENGINE_BEGIN

class GameObject;

class GameObjectComponent : public BaseComponent
{
public:
    GameObjectComponent(const GameObjectComponent& other);

    GameObjectComponent(GameObjectComponent&& other) noexcept;

    GameObjectComponent() = default;

    GameObjectComponent& operator=(const GameObjectComponent& other)
    {
        if (this == &other)
            return *this;
        BaseComponent::operator =(other);
        return *this;
    }

    GameObjectComponent& operator=(GameObjectComponent&& other) noexcept
    {
        if (this == &other)
            return *this;
        BaseComponent::operator =(other);
        return *this;
    }


    virtual void init(const GameObject* parent);

#pragma region BaseComponent
    void update() override;
    void end() override;
   ~GameObjectComponent() override;
#pragma endregion
};

ENGINE_END
