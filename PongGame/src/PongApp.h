#pragma once
#include "core/engine/Engine.h"

class PongApp : public GE::EngineCore
{
public:
    
};


std::shared_ptr<GE::EngineCore> GE::create_engine()
{
    return EngineCore::get<PongApp>();
}
