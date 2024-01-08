#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

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

        virtual void draw(std::shared_ptr<sf::RenderWindow>& window) const = 0;

        [[nodiscard]] virtual std::shared_ptr<DrawableEntity> GetDrawableEntity() const = 0;
    };


ENGINE_END
