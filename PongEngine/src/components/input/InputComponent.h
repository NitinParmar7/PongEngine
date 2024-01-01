#pragma once
#include <memory>
#include <vector>

#include "CoreTypeDef.h"
#include "core/EngineComponent.h"


ENGINE_BEGIN
    class InputListenerComponent;

    typedef std::shared_ptr<InputListenerComponent> TypeInputListenerComponent;

    class InputComponent : public EngineComponent
    {
    public:
#pragma region EngineComponent
        void init(const EngineCore* parent) override = 0;
        void update() override;
        void end() override = 0;
#pragma endregion

        void AddInputListenerComponent(const TypeInputListenerComponent& input_listener_component);

        bool RemoveInputListenerComponent(const TypeInputListenerComponent& input_listener_component);

    private:
        std::vector<TypeInputListenerComponent> input_listener_components_;
    };


ENGINE_END
