﻿#pragma once
#include "BaseComponent.h"
#include "../../CoreTypeDef.h"

ENGINE_BEGIN

class EngineCore;

class EngineComponent : public BaseComponent
{
public:
    ~EngineComponent() override;

    virtual void init(const EngineCore* parent);

    virtual void update() override = 0;

    virtual void end() override = 0;

private:

    const EngineCore* parent_;

};

ENGINE_END
