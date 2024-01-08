#include "TextEntity.h"

ENGINE_BEGIN
    TextEntity::TextEntity(const TextEntity& other): DrawableEntity(other),
                                                     m_open_sans(std::make_unique<sf::Font>(*other.m_open_sans)),
                                                     m_text(std::make_unique<sf::Text>(*other.m_text))
    {
    }

    TextEntity::TextEntity(TextEntity&& other) noexcept: DrawableEntity(std::move(other)),
                                                         m_open_sans(std::move(other.m_open_sans)),
                                                         m_text(std::move(other.m_text))
    {
    }

    TextEntity& TextEntity::operator=(const TextEntity& other)
    {
        if (this == &other)
            return *this;
        DrawableEntity::operator =(other);
        m_open_sans = std::make_unique<sf::Font>(*other.m_open_sans);
        m_text = std::make_unique<sf::Text>(*other.m_text);
        return *this;
    }

    TextEntity& TextEntity::operator=(TextEntity&& other) noexcept
    {
        if (this == &other)
            return *this;
        DrawableEntity::operator =(std::move(other));
        m_open_sans = std::move(other.m_open_sans);
        m_text = std::move(other.m_text);
        return *this;
    }

    TextEntity::~TextEntity()
    {
        m_open_sans.release();
        m_text.release();
    }


    std::shared_ptr<DrawableEntity> TextEntity::GetDrawableEntity() const
    {
        return std::make_shared<TextEntity>(*this);
    }

TextEntity::TextEntity(const std::string& text_to_show) : DrawableEntity()
{
    m_open_sans = std::make_unique<sf::Font>();
    m_open_sans->loadFromFile("../resources/font/open_sans/static/OpenSans-Regular.ttf");
    m_text = std::make_unique<sf::Text>(text_to_show, *m_open_sans);
}

TextEntity::TextEntity(const std::string& text_to_show, sf::Text::Style style, unsigned character_size)
{
    m_open_sans = std::make_unique<sf::Font>();
    m_open_sans->loadFromFile("../resources/font/open_sans/static/OpenSans-Regular.ttf");
    m_text = std::make_unique<sf::Text>(text_to_show, *m_open_sans, character_size);
    m_text->setStyle(style);
}

void TextEntity::draw(std::shared_ptr<sf::RenderWindow>& window) const
{
    window->draw(*m_text);
}


ENGINE_END
