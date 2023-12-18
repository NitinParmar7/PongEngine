#pragma once

class Scene
{
public:
    virtual ~Scene() = default;

    virtual void EnterScene() = 0;
    
};
