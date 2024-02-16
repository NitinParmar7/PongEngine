#pragma once
#include <memory>
#include "GameObjectComponent.h"



namespace GE {
    class ListableEngineComponent;

    class ListableGameObjectComponent : public GameObjectComponent
    {
    public:
        explicit ListableGameObjectComponent(const GameObjectComponent& other)
            : GameObjectComponent(other)
        {
        }

        explicit ListableGameObjectComponent(GameObjectComponent&& other)
            : GameObjectComponent(other)
        {
        }

        explicit ListableGameObjectComponent(const std::shared_ptr<ListableEngineComponent>& engine_component);

        ListableGameObjectComponent() = default;

        ~ListableGameObjectComponent() override;

    private:
        std::shared_ptr<ListableEngineComponent> m_engine_component;
    };

}
