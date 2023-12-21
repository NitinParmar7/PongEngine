#include "SceneManager.h"
#include "Scene.h"

ENGINE_BEGIN
void SceneManager::init(const EngineCore* parent)
{
	EngineComponent::init(parent);
	scenes_.clear();
	current_scene_ = scenes_.begin();
}

void SceneManager::update()
{
	if(current_scene_ != scenes_.end())
	{
		current_scene_->get()->UpdateScene();
	}
}

void SceneManager::end()
{
	for (const auto element : scenes_)
	{
		element->ExitScene();
	}
	current_scene_ = scenes_.end();
	scenes_.clear();
}


void SceneManager::AddScene(const SceneBehaviourData<scene_unique_ptr>& scene_to_add)
{
	scene_behavior_.push_back(scene_to_add);
}

void SceneManager::RemoveScene(const SceneBehaviourData<scene_unique_ptr>& scene_to_remove)
{
	scene_behavior_.push_back(scene_to_remove);
}


void SceneManager::NextScene()
{
	scene_behavior_.push_back(static_cast<SceneBehaviourData<scene_unique_ptr>>(ESCENE_BEHAVIOUR::Next_Scene));
}

void SceneManager::PreviousScene()
{
	scene_behavior_.push_back(static_cast<SceneBehaviourData<scene_unique_ptr>>(ESCENE_BEHAVIOUR::Previous_Scene));
}




ENGINE_END


