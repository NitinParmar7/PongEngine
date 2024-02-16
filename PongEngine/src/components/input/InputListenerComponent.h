#pragma once
#include <SFML/Graphics.hpp>
#include "../core/GameObjectComponent.h"
#include "components/core/ListableGameObjectComponent.h"

namespace GE {
    using Key = sf::Keyboard::Key;


    class InputListenerComponent : ListableGameObjectComponent
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

}
