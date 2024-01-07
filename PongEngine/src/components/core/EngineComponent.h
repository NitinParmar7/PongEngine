#pragma once
#include <utility>

#include "BaseComponent.h"
#include "../../CoreTypeDef.h"

ENGINE_BEGIN
    class EngineCore;

    class EngineComponent : public BaseComponent
    {
    public:
        EngineComponent(const EngineComponent& other);

        EngineComponent(EngineComponent&& other) noexcept;

        EngineComponent& operator=(const EngineComponent& other);

        EngineComponent& operator=(EngineComponent&& other) noexcept;

        explicit EngineComponent(const EngineCore* parent);

        ~EngineComponent() override;

        virtual void init(const EngineCore* parent);

#pragma region BaseComponent

        void update() override = 0;

        void end() override = 0;

#pragma endregion

        [[nodiscard]] const EngineCore* GetParent() const
        {
            return m_parent_;
        }

    private:
        const EngineCore* m_parent_;
    };

ENGINE_END
