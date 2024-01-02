#pragma once
#include <cstdint>

#include "../../CoreTypeDef.h"

ENGINE_BEGIN
    enum class ECOLLISION_PROFILE : uint8_t
{
    No_Collision,
    Overlap,
    Hit
};


ENGINE_END