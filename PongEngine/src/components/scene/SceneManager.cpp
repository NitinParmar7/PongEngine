#include "SceneManager.h"

#include "Scene.h"

ENGINE_BEGIN
	SceneManager::SceneManager()
{
	current_scene_ = scenes_.begin();
}

void SceneManager::AddScene(const std::unique_ptr<Scene>& scene_to_add)
{
	scenes_.push_back(scene_to_add);
}

void SceneManager::RemoveScene(const std::unique_ptr<Scene>& scene_to_remove)
{
	scene_to_remove->ExitScene();
	std::erase(scenes_, scene_to_remove);
}


void SceneManager::NextScene()
{
	if(current_scene_ != scenes_.end())
	{
		current_scene_->get()->ExitScene();
		++current_scene_;
		current_scene_->get()->EnterScene();
	}
}

void SceneManager::PreviousScene()
{
	if(current_scene_ != scenes_.begin())
	{
		current_scene_->get()->ExitScene();
		--current_scene_;
		current_scene_->get()->EnterScene();
	}
}






ENGINE_END
