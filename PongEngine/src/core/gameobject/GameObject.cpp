#include "GameObject.h"


ENGINE_BEGIN
    // template <typename T, typename ... Args>
    // std::shared_ptr<T> GameObject::AddComponent(Args&&... args)
    // {
    //     static_assert(std::is_base_of_v<GameObjectComponent, T>, "T must be derived class of GameObjectComponent");
    //     auto game_object_component = std::make_shared<T>(std::forward<Args>(args)...);
    //     m_game_object_components.emplace_back(game_object_component);
    //     return game_object_component;
    // }
    //
    // template <typename T>
    // void GameObject::RemoveComponent(const std::shared_ptr<T>& component)
    // {
    //     static_assert(std::is_base_of_v<GameObjectComponent, T>, "T must be derived class of GameObjectComponent");
    //   //  auto it = std::remove(m_game_object_components)
    // }

    std::vector<std::shared_ptr<GameObjectComponent>> GameObject::GetGameObjectComponents() const
    {
        return m_game_object_components;
    }

ENGINE_END
