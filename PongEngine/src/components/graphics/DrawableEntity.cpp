#include "DrawableEntity.h"

ENGINE_BEGIN

    DrawableEntity::DrawableEntity(const DrawableEntity& other) = default;

    DrawableEntity::DrawableEntity(DrawableEntity&& other) noexcept: sf::Drawable(other)
    {
    }

    DrawableEntity& DrawableEntity::operator=(const DrawableEntity& other)
    {
        if (this == &other)
            return *this;
        sf::Drawable::operator =(other);
        return *this;
    }

    DrawableEntity& DrawableEntity::operator=(DrawableEntity&& other) noexcept
    {
        if (this == &other)
            return *this;
        sf::Drawable::operator =(other);
        return *this;
    }

    DrawableEntity::~DrawableEntity()
    = default;

    void DrawableEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

std::shared_ptr<DrawableEntity> DrawableEntity::GetDrawableEntity() const
{
    return nullptr;
}

ENGINE_END
