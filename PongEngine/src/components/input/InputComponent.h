#pragma once
#include <memory>
#include <vector>

#include "CoreTypeDef.h"
#include "core/EngineComponent.h"


ENGINE_BEGIN

class InputListenerComponent;

class InputComponent : public EngineComponent
{
public:

    bool AddInputListenerComponent(const std::shared_ptr<InputListenerComponent> input_listener_component);



private:

    std::vector<std::shared_ptr<InputListenerComponent>> input_listener_components_;

};


ENGINE_END
