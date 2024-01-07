#pragma once
#include <cstdint>
#include <memory>
#include <vector>

#include "../../CoreTypeDef.h"
#include "../../core/gameobject/GameObject.h"

ENGINE_BEGIN
    class Scene
    {
    public:
        Scene(const Scene& other)
        = default;

        Scene(Scene&& other) noexcept
        {
        }

        Scene& operator=(const Scene& other)
        {
            if (this == &other)
                return *this;
            return *this;
        }

        Scene& operator=(Scene&& other) noexcept
        {
            if (this == &other)
                return *this;
            return *this;
        }

        Scene() = default;

        virtual ~Scene() = default;

        virtual void EnterScene() = 0;

        virtual void UpdateScene() = 0;

        virtual void ExitScene() = 0;

        [[nodiscard]] virtual uint8_t getSceneID() const { return m_scene_id_; };

        // template<typename T, typename... Args>
        // std::shared_ptr<T> AddGameObject(Args&&... args);
        //
        // template<typename T>
        // void RemoveGameObjects(const std::shared_ptr<T>& game_object);

        [[nodiscard]] std::vector<std::shared_ptr<GameObject>> GetGameObjects() const;

    protected:
        uint8_t m_scene_id_;

        std::vector<std::shared_ptr<GameObject>> m_game_objects;
    };


ENGINE_END
