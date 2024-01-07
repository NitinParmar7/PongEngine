#pragma once
#include "components/scene/Scene.h"

class IntroScene : public GE::Scene
{
public:
    IntroScene();

    ~IntroScene() override;
    void EnterScene() override;
    void UpdateScene() override;
    void ExitScene() override;


private:


};
