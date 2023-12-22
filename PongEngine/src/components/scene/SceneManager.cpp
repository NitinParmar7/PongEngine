#include "SceneManager.h"

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
	for (const auto& scene : scenes_)
	{
		scene->ExitScene();
	}
	current_scene_ = scenes_.end();
	scenes_.clear();
}


void SceneManager::AddScene(SceneBehaviourData<Scene> scene_to_add)
{
	scene_behavior_.emplace_back(std::move(scene_to_add));
}

void SceneManager::RemoveScene(SceneBehaviourData<Scene> scene_to_remove)
{
	scene_behavior_.emplace_back(std::move(scene_to_remove));
}

void SceneManager::NextScene()
{
	scene_behavior_.emplace_back(ESCENE_BEHAVIOUR::Next_Scene);
}

void SceneManager::PreviousScene()
{
	scene_behavior_.emplace_back(ESCENE_BEHAVIOUR::Previous_Scene);
}

void SceneManager::ProcessScene()
{
	if (!scene_behavior_.empty())
	{
		auto behaviour_data = std::move(scene_behavior_.front());
		scene_behavior_.pop_front();

		switch (behaviour_data.behaviour)
		{
		case ESCENE_BEHAVIOUR::Add_Scene:
			scenes_.emplace_back(std::move(behaviour_data.data));
			if(scenes_.size() == 1)
			{
				current_scene_ = scenes_.begin();
			}
			break;
		case ESCENE_BEHAVIOUR::Remove_Scene:
			// Handle removal if needed
			if((*current_scene_) == behaviour_data.data)
			{
				current_scene_ = scenes_.erase(std::remove(scenes_.begin(), scenes_.end(), behaviour_data.data));
			}
			else
			{
				scenes_.erase(std::remove(scenes_.begin(), scenes_.end(), behaviour_data.data));
			}
			break;
		case ESCENE_BEHAVIOUR::Next_Scene:
			// Handle next scene if needed
			if (current_scene_ != scenes_.end())
			{
				if(*current_scene_)
				{
					current_scene_->get()->ExitScene();
				}
				++current_scene_;
				if(*current_scene_)
				{
					current_scene_->get()->EnterScene();
				}
			}
			break;
		case ESCENE_BEHAVIOUR::Previous_Scene:
			// Handle previous scene if needed
			if (current_scene_ != scenes_.begin())
			{
				if(*current_scene_)
				{
					current_scene_->get()->ExitScene();
				}
				--current_scene_;
				if(*current_scene_)
				{
					current_scene_->get()->EnterScene();
				}			}
			break;
		}
	}
}



ENGINE_END


