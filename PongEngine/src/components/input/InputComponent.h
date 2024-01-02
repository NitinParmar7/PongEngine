#pragma once
#include <memory>

#include "../../CoreTypeDef.h"
#include "../core/ListableEngineComponent.h"


ENGINE_BEGIN
    class InputListenerComponent;

    typedef std::shared_ptr<InputListenerComponent> TypeInputListenerComponent;

    class InputComponent : public ListableEngineComponent
    {
    public:
#pragma region EngineComponent
        void init(const EngineCore* parent) override;
        void update() override;
        void end() override;
#pragma endregion

    };


ENGINE_END
