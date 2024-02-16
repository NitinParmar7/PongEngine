#include "TextComponent.h"

#include "core/engine/Engine.h"
#include "core/engine/EngineData.h"

namespace GE {
    TextComponent::TextComponent(const TextComponent& other): DrawableComponent(other),
                                                     m_open_sans(std::make_unique<sf::Font>(*other.m_open_sans)),
                                                     m_text(std::make_unique<sf::Text>(*other.m_text))
    {
    }

    TextComponent::TextComponent(TextComponent&& other) noexcept: DrawableComponent(std::move(other)),
                                                         m_open_sans(std::move(other.m_open_sans)),
                                                         m_text(std::move(other.m_text))
    {
    }

    TextComponent& TextComponent::operator=(const TextComponent& other)
    {
        if (this == &other)
            return *this;
        DrawableComponent::operator =(other);
        m_open_sans = std::make_unique<sf::Font>(*other.m_open_sans);
        m_text = std::make_unique<sf::Text>(*other.m_text);
        return *this;
    }

    TextComponent& TextComponent::operator=(TextComponent&& other) noexcept
    {
        if (this == &other)
            return *this;
        DrawableComponent::operator =(std::move(other));
        m_open_sans = std::move(other.m_open_sans);
        m_text = std::move(other.m_text);
        return *this;
    }

    TextComponent::~TextComponent()
    {
        m_open_sans.release();
        m_text.release();
    }



TextComponent::TextComponent(const std::string& text_to_show, sf::Text::Style style, unsigned character_size)
{
    m_open_sans = std::make_unique<sf::Font>();
    m_open_sans->loadFromFile("../resources/font/open_sans/static/OpenSans-Regular.ttf");
    m_text = std::make_unique<sf::Text>(text_to_show, *m_open_sans, character_size);
    m_text->setStyle(style);
        m_text->setPosition(320, 200);
}

void TextComponent::draw(std::shared_ptr<sf::RenderWindow>& window) const
{
    window->draw(*m_text);
}


}
