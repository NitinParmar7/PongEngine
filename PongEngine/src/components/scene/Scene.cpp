#include "Scene.h"

ENGINE_BEGIN
    // template <typename T, typename ... Args>
    // std::shared_ptr<T> Scene::AddGameObject(Args&&... args)
    // {
    //     static_assert(std::is_base_of_v<GameObject, T>, "T must be derived from GameObject");
    //     auto game_object = std::make_shared<T>(std::forward<Args>(args)...);
    //     m_game_objects.emplace_back(game_object);
    //     return game_object;
    // }
    //
    // template <typename T>
    // void Scene::RemoveGameObjects(const std::shared_ptr<T>& game_object)
    // {
    //     static_assert(std::is_base_of_v<GameObject,T>("T must be derived from GameObject"));
    //
    //     auto it = std::remove(m_game_objects.begin(), m_game_objects.end(), game_object);
    //
    //     if(it != m_game_objects.end())
    //     {
    //         m_game_objects.erase(it, m_game_objects.end());
    //     }
    //
    // }

    std::vector<std::shared_ptr<GameObject>> Scene::GetGameObjects() const
    {
        return m_game_objects;
    }


ENGINE_END
