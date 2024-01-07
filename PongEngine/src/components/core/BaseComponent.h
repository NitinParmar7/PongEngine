#pragma once
#include "../../CoreTypeDef.h"

ENGINE_BEGIN

class BaseComponent  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:

    BaseComponent() = default;

    virtual ~BaseComponent() = default;

    virtual void update() = 0;

    virtual void end() = 0;
};

ENGINE_END