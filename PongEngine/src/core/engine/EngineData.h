// ReSharper disable CppInconsistentNaming
#pragma once
#include "../../CoreTypeDef.h"

ENGINE_BEGIN


struct EngineData
{
    EngineData(const unsigned width, const unsigned height, const std::string_view& title)
        : WIDTH(width),
          HEIGHT(height),
          TITLE(title)
    {
    }

    const unsigned int WIDTH;

    const unsigned int HEIGHT;

    std::string_view TITLE;

};




ENGINE_END