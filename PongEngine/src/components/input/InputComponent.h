#pragma once
#include <memory>

#include "../../CoreTypeDef.h"
#include "../core/ListableEngineComponent.h"


ENGINE_BEGIN
    class InputListenerComponent;

    using TypeInputListenerComponent = std::shared_ptr<InputListenerComponent>;

    class InputComponent : public ListableEngineComponent
    {
    public:
        explicit InputComponent(const EngineCore* parent);

#pragma region EngineComponent


        void init(const EngineCore* parent) override;
        void update() override;
        void end() override;
#pragma endregion
    };


ENGINE_END
