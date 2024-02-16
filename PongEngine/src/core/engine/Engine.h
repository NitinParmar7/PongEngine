#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

#include "EngineData.h"
#include "../../components/collision/CollisionHandler.h"

namespace GE {
    class EngineComponent;
    class RendererComponent;
    class InputComponent;

    class SceneManager;

    class EngineCore
    {
    public:
        EngineCore(const EngineCore&) = delete;

        EngineCore(const EngineCore&&) = delete;

        EngineCore& operator=(const EngineCore&) = delete;

        EngineCore& operator=(const EngineCore&&) = delete;

        template <typename T>
        static std::shared_ptr<T> get()
        {
            static_assert(std::is_base_of_v<EngineCore, T>, "T must be derived from EngineCore");
            static std::shared_ptr<T> instance(new T());
            return instance;
        }

        template <class T>
        std::shared_ptr<T> CreateComponent();

        virtual void init();

        void run();

        virtual void exit();

        [[nodiscard]] virtual std::shared_ptr<EngineData> GetData() const;

        [[nodiscard]] std::shared_ptr<CollisionHandler> GetCollisionHandler() const;

        [[nodiscard]] std::shared_ptr<sf::RenderWindow> GetRenderWindow() const;

        [[nodiscard]] std::shared_ptr<SceneManager> GetSceneManager() const;

        [[nodiscard]] std::shared_ptr<InputComponent> GetInputComponent() const;

        [[nodiscard]] std::shared_ptr<RendererComponent> GetRendererComponent() const;

        [[nodiscard]] std::vector<std::shared_ptr<EngineComponent>> GetEngineComponents() const;

        [[nodiscard]] virtual std::string_view GetTitle() const;

        [[nodiscard]] virtual unsigned int GetWidth() const;

        [[nodiscard]] virtual unsigned int GetHeight() const;

    protected:
        EngineCore() = default;

        virtual ~EngineCore() = default;

    private:
        std::shared_ptr<EngineData> m_data_;

        std::shared_ptr<sf::RenderWindow> m_render_window_;
        std::shared_ptr<SceneManager> m_scene_manager_;
        std::shared_ptr<InputComponent> m_input_component_;
        std::shared_ptr<RendererComponent> m_renderer_component_;
        std::shared_ptr<CollisionHandler> m_collision_handler_;

        std::vector<std::shared_ptr<EngineComponent>> m_engine_components_;
    };


    std::shared_ptr<EngineCore> create_engine();


}
