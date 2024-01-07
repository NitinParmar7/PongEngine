#pragma once
#include <memory>
#include <vector>

#include "CoreTypeDef.h"

ENGINE_BEGIN

class Helper
{
public:

    template <typename Derived, typename Base, typename Array, typename ... Args>
    static std::shared_ptr<Derived> AddObject(std::vector<std::shared_ptr<Array>> object_array, Args&&... args);

    template <typename Derived, typename Base, typename Array>
    static bool RemoveObject(std::shared_ptr<Derived>& object, std::vector<std::shared_ptr<Array>> object_array);

};

ENGINE_END
