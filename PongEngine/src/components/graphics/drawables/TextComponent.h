#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "..\core\DrawableComponent.h"

namespace GE {

    class TextComponent : public DrawableComponent
    {
    public:
        TextComponent(const TextComponent& other);

        TextComponent(TextComponent&& other) noexcept;

        TextComponent& operator=(const TextComponent& other);

        TextComponent& operator=(TextComponent&& other) noexcept;

        ~TextComponent() override;

        explicit TextComponent(const std::string& text_to_show, sf::Text::Style style = sf::Text::Regular,  unsigned int character_size = 30);

        void draw(std::shared_ptr<sf::RenderWindow>& window) const override;

    private:
        std::unique_ptr<sf::Font> m_open_sans;

        std::unique_ptr<sf::Text> m_text;
    };

}
