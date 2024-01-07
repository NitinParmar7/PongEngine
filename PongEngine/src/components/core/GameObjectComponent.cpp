#include "GameObjectComponent.h"

ENGINE_BEGIN

GameObjectComponent::GameObjectComponent(GameObjectComponent&& other) noexcept: BaseComponent(other)
    {
    }

GameObjectComponent& GameObjectComponent::operator=(const GameObjectComponent& other)
{
    if (this == &other)
        return *this;
    BaseComponent::operator =(other);
    return *this;
}

GameObjectComponent& GameObjectComponent::operator=(GameObjectComponent&& other) noexcept
{
    if (this == &other)
        return *this;
    BaseComponent::operator =(other);
    return *this;
}

void GameObjectComponent::init(const GameObject* parent)
{
}

void GameObjectComponent::update()
{
}

void GameObjectComponent::end()
{
}

GameObjectComponent::~GameObjectComponent()
= default;

ENGINE_END
