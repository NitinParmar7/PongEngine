#pragma once
#include <cstdint>

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

    virtual void RegisterScene() = 0;

    virtual void EnterScene() = 0;

    virtual void UpdateScene() = 0;

    virtual void ExitScene() = 0;

private:

    uint8_t scene_id_;
};
