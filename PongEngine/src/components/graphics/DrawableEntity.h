#pragma once
#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include "CoreTypeDef.h"

ENGINE_BEGIN

    // ReSharper disable once CppClassCanBeFinal
    class DrawableEntity : sf::Drawable
{
public:
    DrawableEntity(const DrawableEntity& other);

    DrawableEntity(DrawableEntity&& other) noexcept;

    DrawableEntity& operator=(const DrawableEntity& other);

    DrawableEntity& operator=(DrawableEntity&& other) noexcept;

    ~DrawableEntity() override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    [[nodiscard]] virtual std::shared_ptr<DrawableEntity> GetDrawableEntity() const;
};


ENGINE_END