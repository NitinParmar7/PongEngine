#pragma once
#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include "../src/CoreTypeDef.h"

ENGINE_BEGIN
    // ReSharper disable once CppClassCanBeFinal
    class DrawableEntity
    {

    public:

        DrawableEntity() = default;

        DrawableEntity(const DrawableEntity& other);

        DrawableEntity(DrawableEntity&& other) noexcept;

        DrawableEntity& operator=(const DrawableEntity& other);

        DrawableEntity& operator=(DrawableEntity&& other) noexcept;

        virtual ~DrawableEntity();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

        [[nodiscard]] virtual std::shared_ptr<DrawableEntity> GetDrawableEntity() const;
    };


ENGINE_END
