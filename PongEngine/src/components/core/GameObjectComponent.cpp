#include "GameObjectComponent.h"

ENGINE_BEGIN

GameObjectComponent::GameObjectComponent(GameObjectComponent&& other) noexcept: BaseComponent(other)
    {
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
