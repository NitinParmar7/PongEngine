#pragma once
#include <cstdint>
#include "../../CoreTypeDef.h"

ENGINE_BEGIN

class Scene
{
public:
    Scene(const Scene& other)
    = default;

    Scene(Scene&& other) noexcept
    {
    }

    Scene& operator=(const Scene& other)
    {
        if (this == &other)
            return *this;
        return *this;
    }

    Scene& operator=(Scene&& other) noexcept
    {
        if (this == &other)
            return *this;
        return *this;
    }

    Scene() = default;

    virtual ~Scene() = default;

    virtual void EnterScene() = 0;

    virtual void UpdateScene() = 0;

    virtual void ExitScene() = 0;

    [[nodiscard]] virtual inline uint8_t getSceneID() const {return  scene_id_;};

private:

    uint8_t scene_id_;
};

ENGINE_END


