#pragma once
#include <memory>
#include <vector>
#include "../src/CoreTypeDef.h"

ENGINE_BEGIN
    class GameObjectComponent;

    class GameObject
    {
    public:
        virtual void Start() = 0;

        virtual void Update(float delta_time) = 0;

        virtual void End() = 0;

        // template<typename T, typename... Args>
        // std::shared_ptr<T> AddComponent(Args&&... args);
        //
        // template<typename T>
        // void RemoveComponent(const std::shared_ptr<T>& component);

        [[nodiscard]] std::vector<std::shared_ptr<GameObjectComponent>> GetGameObjectComponents() const;

    protected:
        std::vector<std::shared_ptr<GameObjectComponent>> m_game_object_components;
    };


ENGINE_END
