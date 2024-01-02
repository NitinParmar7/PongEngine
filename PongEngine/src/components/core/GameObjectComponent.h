#pragma once
#include "BaseComponent.h"


ENGINE_BEGIN

class GameObject;

class GameObjectComponent : public BaseComponent
{
public:

    ~GameObjectComponent() override;

    virtual void init(const GameObject* parent);

#pragma region BaseComponent
    void update() override;
    void end() override;
#pragma endregion
};

ENGINE_END
