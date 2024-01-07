#pragma once
#include <deque>
#include <memory>
#include <vector>
#include "SceneDef.h"
#include "Scene.h"
#include "../core/EngineComponent.h"

ENGINE_BEGIN
    class SceneManager : public EngineComponent
    {
    public:
#pragma region EngineComponent

        explicit SceneManager(const EngineCore* parent);

        void init(const EngineCore* parent) override;
        void update() override;
        void end() override;

#pragma endregion


        void AddScene(SceneBehaviourData<Scene> scene_to_add);

        void RemoveScene(SceneBehaviourData<Scene> scene_to_remove);

        void NextScene();

        void PreviousScene();

        void ProcessScene();

    private:
        std::vector<std::unique_ptr<Scene>>::iterator m_current_scene_;

        std::vector<std::unique_ptr<Scene>> m_scenes_;

        std::deque<SceneBehaviourData<Scene>> m_scene_behavior_;
    };

ENGINE_END
