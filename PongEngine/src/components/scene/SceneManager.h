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

	void init(const EngineCore* parent) override;
	void update() override;
	void end() override;

#pragma endregion

	SceneManager() = default;

	void AddScene(SceneBehaviourData<Scene> scene_to_add);

	void RemoveScene(SceneBehaviourData<Scene> scene_to_remove);

	void NextScene();

	void PreviousScene();

	void ProcessScene();

private:

	std::vector<std::unique_ptr<Scene>>::iterator current_scene_;

	std::vector<std::unique_ptr<Scene>> scenes_;

	std::deque<SceneBehaviourData<Scene>> scene_behavior_;

};

ENGINE_END
