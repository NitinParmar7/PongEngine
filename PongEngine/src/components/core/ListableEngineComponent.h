#pragma once
#include <memory>
#include <vector>
#include "CoreTypeDef.h"
#include "EngineComponent.h"


ENGINE_BEGIN

class GameObjectComponent;

typedef std::shared_ptr<GameObjectComponent> LComponent;

class ListableEngineComponent : public EngineComponent
{
public:
    ~ListableEngineComponent() override;

#pragma region EngineComponent

    void init(const EngineCore* parent) override;
    void update() override;
    void end() override;

#pragma endregion

    virtual void AddComponent(const LComponent& component);

    virtual bool RemoveComponent(const LComponent& component);

protected:

    std::vector<LComponent> components_;
};

ENGINE_END
