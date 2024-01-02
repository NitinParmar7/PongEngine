#pragma once
#include <cstdint>

#include "../../CoreTypeDef.h"

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
    ESCENE_BEHAVIOUR behaviour = ESCENE_BEHAVIOUR::None;
    std::unique_ptr<T> data = nullptr;

    SceneBehaviourData() : data(nullptr) {} // Default-constructed unique_ptr

    SceneBehaviourData(std::unique_ptr<T> data = nullptr) : data(std::move(data)) {}

    explicit SceneBehaviourData(const ESCENE_BEHAVIOUR behaviour) : behaviour(behaviour), data(nullptr) {}

    SceneBehaviourData(const ESCENE_BEHAVIOUR behaviour, std::unique_ptr<T> data)
        : behaviour(behaviour), data(std::move(data)) {}
};


ENGINE_END
