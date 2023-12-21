#pragma once
#include <cstdint>

#include "../../core/CoreTypeDef.h"

ENGINE_BEGIN

enum class ESCENE_BEHAVIOUR : uint8_t
{
    None,
    Add_Scene,
    Remove_Scene,
    Next_Scene,
    Previous_Scene
};

template<typename T>
struct SceneBehaviourData
{

    SceneBehaviourData()
        :behaviour(ESCENE_BEHAVIOUR::None),
        scene(nullptr){}

    explicit SceneBehaviourData(const ESCENE_BEHAVIOUR behaviour)
     : behaviour(behaviour),
       scene(nullptr){}

    SceneBehaviourData(const ESCENE_BEHAVIOUR behaviour, const std::unique_ptr<T>& scene)
        : behaviour(behaviour),
          scene(scene){}

    ESCENE_BEHAVIOUR behaviour = ESCENE_BEHAVIOUR::None;
    std::unique_ptr<T> scene = nullptr;

};


ENGINE_END
