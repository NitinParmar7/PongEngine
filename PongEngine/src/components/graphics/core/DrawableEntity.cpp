#include "DrawableEntity.h"

ENGINE_BEGIN
    DrawableEntity::DrawableEntity(const DrawableEntity& other) = default;

    DrawableEntity::DrawableEntity(DrawableEntity&& other) noexcept
    {
    }

    DrawableEntity& DrawableEntity::operator=(const DrawableEntity& other)
    {
        if (this == &other)
            return *this;
        return *this;
    }

    DrawableEntity& DrawableEntity::operator=(DrawableEntity&& other) noexcept
    {
        if (this == &other)
            return *this;
        return *this;
    }

    DrawableEntity::~DrawableEntity()
    = default;


    std::shared_ptr<DrawableEntity> DrawableEntity::GetDrawableEntity() const
    {
        return nullptr;
    }

ENGINE_END
