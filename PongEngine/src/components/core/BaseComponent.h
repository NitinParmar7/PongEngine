﻿#pragma once
#include "../../core/CoreTypeDef.h"

ENGINE_BEGIN

class BaseComponent
{
public:

    virtual void update() = 0;

    virtual void end() = 0;
};

ENGINE_END