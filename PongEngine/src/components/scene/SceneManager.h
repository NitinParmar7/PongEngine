#pragma once
#include <memory>
#include <unordered_map>
#include <vector>

#include "SceneDef.h"
#include "../../core/CoreTypeDef.h"
#include "../core/EngineComponent.h"
class Scene;

ENGINE_BEGIN


typedef std::unique_ptr<Scene> scene_unique_ptr;

class SceneManager : public EngineComponent
{
public:

#pragma region EngineComponent

	void init(const EngineCore* parent) override;
	void update() override;
	void end() override;

#pragma endregion

	SceneManager() = default;

	void AddScene(const SceneBehaviourData<scene_unique_ptr>& scene_to_add);

	void RemoveScene(const SceneBehaviourData<scene_unique_ptr>& scene_to_remove);

	void NextScene();

	void PreviousScene();

private:

	std::vector<scene_unique_ptr>::iterator current_scene_;

	std::vector<scene_unique_ptr> scenes_;

	std::vector<SceneBehaviourData<scene_unique_ptr>> scene_behavior_;

};

ENGINE_END
