#pragma once
#include "CoreTypeDef.h"
#include "GameObjectComponent.h"
#include "PongEngine.h"


ENGINE_BEGIN
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

ENGINE_END
