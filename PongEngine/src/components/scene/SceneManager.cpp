#include "SceneManager.h"

ENGINE_BEGIN
#pragma region EngineComponent
    SceneManager::SceneManager(const EngineCore* parent): EngineComponent(parent)
    {
    }

    void SceneManager::init(const EngineCore* parent)
    {
        EngineComponent::init(parent);
        m_scenes_.clear();
        m_current_scene_ = m_scenes_.begin();
    }

    void SceneManager::update()
    {
        if (m_current_scene_ != m_scenes_.end())
        {
            m_current_scene_->get()->UpdateScene();
        }
    }

    void SceneManager::end()
    {
        for (const auto& scene : m_scenes_)
        {
            scene->ExitScene();
        }
        m_current_scene_ = m_scenes_.end();
        m_scenes_.clear();
    }

#pragma endregion


    void SceneManager::AddScene(SceneBehaviourData<Scene> scene_to_add)
    {
        m_scene_behavior_.emplace_back(std::move(scene_to_add));
    }

    void SceneManager::RemoveScene(SceneBehaviourData<Scene> scene_to_remove)
    {
        m_scene_behavior_.emplace_back(std::move(scene_to_remove));
    }

    void SceneManager::NextScene()
    {
        m_scene_behavior_.emplace_back(ESCENE_BEHAVIOUR::Next_Scene);
    }

    void SceneManager::PreviousScene()
    {
        m_scene_behavior_.emplace_back(ESCENE_BEHAVIOUR::Previous_Scene);
    }

    void SceneManager::ProcessScene()
    {
        if (!m_scene_behavior_.empty())
        {
            auto behaviour_data = std::move(m_scene_behavior_.front());
            m_scene_behavior_.pop_front();

            switch (behaviour_data.behaviour)
            {
            case ESCENE_BEHAVIOUR::Add_Scene:
                m_scenes_.emplace_back(std::move(behaviour_data.data));
                if (m_scenes_.size() == 1)
                {
                    m_current_scene_ = m_scenes_.begin();
                }
                break;
            case ESCENE_BEHAVIOUR::Remove_Scene:
                // Handle removal if needed
                if ((*m_current_scene_) == behaviour_data.data)
                {
                    m_current_scene_ = m_scenes_.erase(
                        std::remove(m_scenes_.begin(), m_scenes_.end(), behaviour_data.data));
                }
                else
                {
                    m_scenes_.erase(std::remove(m_scenes_.begin(), m_scenes_.end(), behaviour_data.data));
                }
                break;
            case ESCENE_BEHAVIOUR::Next_Scene:
                // Handle next scene if needed
                if (m_current_scene_ != m_scenes_.end())
                {
                    if (*m_current_scene_)
                    {
                        m_current_scene_->get()->ExitScene();
                    }
                    ++m_current_scene_;
                    if (*m_current_scene_)
                    {
                        m_current_scene_->get()->EnterScene();
                    }
                }
                break;
            case ESCENE_BEHAVIOUR::Previous_Scene:
                // Handle previous scene if needed
                if (m_current_scene_ != m_scenes_.begin())
                {
                    if (*m_current_scene_)
                    {
                        m_current_scene_->get()->ExitScene();
                    }
                    --m_current_scene_;
                    if (*m_current_scene_)
                    {
                        m_current_scene_->get()->EnterScene();
                    }
                }
                break;
            }
        }
    }


ENGINE_END
