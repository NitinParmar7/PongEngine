#pragma once
#include <SFML/Graphics.hpp>
#include "../src/CoreTypeDef.h"
#include "../core/GameObjectComponent.h"

ENGINE_BEGIN
    typedef sf::Keyboard::Key Key;


    class InputListenerComponent : GameObjectComponent
    {
    public:

#pragma region GameObjectComponent
        void update() override;
        void end() override;
        void init(const GameObject* parent) override;
        ~InputListenerComponent() override;

#pragma endregion

        InputListenerComponent()
            : key_(Key::Unknown)
        {
        }

        explicit InputListenerComponent(const Key key)
            : key_(key)
        {
        }

        void OnClick();

        [[nodiscard]] bool IsPressed() const { return pressed_; }

        void ConsumeInput();

        [[nodiscard]] Key GetKey() const { return key_; }

    private:
        bool pressed_ = false;

        sf::Keyboard::Key key_;
    };

ENGINE_END