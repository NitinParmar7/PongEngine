#pragma once
#include <cstdint>
#include "../../core/CoreTypeDef.h"
#include <vector>
#include <memory>

class Scene;

ENGINE_BEGIN


typedef std::unique_ptr<Scene> scene_unique_ptr;

class SceneManager
{
public:

	SceneManager();

	void AddScene(const scene_unique_ptr& scene_to_add);

	void RemoveScene(const scene_unique_ptr& scene_to_remove);

	void NextScene();

	void PreviousScene();

private:

	std::vector<scene_unique_ptr>::iterator current_scene_;

	std::vector<scene_unique_ptr> scenes_;
};

ENGINE_END
