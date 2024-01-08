#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "CoreTypeDef.h"
#include "components/graphics/core/DrawableEntity.h"

ENGINE_BEGIN
    class TextEntity : public DrawableEntity
    {
    public:
        TextEntity(const TextEntity& other);

        TextEntity(TextEntity&& other) noexcept;

        TextEntity& operator=(const TextEntity& other);

        TextEntity& operator=(TextEntity&& other) noexcept;

        ~TextEntity() override;

        [[nodiscard]] std::shared_ptr<DrawableEntity> GetDrawableEntity() const override;

        explicit TextEntity(const std::string& text_to_show);

        explicit TextEntity(const std::string& text_to_show, sf::Text::Style style = sf::Text::Regular,  unsigned int character_size = 30);

        void draw(std::shared_ptr<sf::RenderWindow>& window) const override;

    private:
        std::unique_ptr<sf::Font> m_open_sans;

        std::unique_ptr<sf::Text> m_text;
    };

ENGINE_END
