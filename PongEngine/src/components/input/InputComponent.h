#pragma once
#include <memory>

#include "../core/ListableEngineComponent.h"


namespace GE {
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


}
