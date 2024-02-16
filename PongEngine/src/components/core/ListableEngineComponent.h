#pragma once
#include <memory>
#include <vector>
#include "EngineComponent.h"


namespace GE {
    class ListableGameObjectComponent;


    using LComponent = std::shared_ptr<ListableGameObjectComponent>;

    class ListableEngineComponent : public EngineComponent
    {
    public:
        explicit ListableEngineComponent(const EngineCore* parent);

        ~ListableEngineComponent() override;

#pragma region EngineComponent

        void init(const EngineCore* parent) override;
        void update() override;
        void end() override;

#pragma endregion

        virtual void AddComponent(const LComponent& component);

        virtual bool RemoveComponent(const LComponent& component);

    protected:
        std::vector<LComponent> m_components_;
    };

}
