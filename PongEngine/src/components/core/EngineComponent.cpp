#include "EngineComponent.h"

namespace GE {
    EngineComponent::EngineComponent(const EngineComponent& other): BaseComponent(other),
                                                                    m_parent_(other.m_parent_)
    {
    }

    EngineComponent::EngineComponent(EngineComponent&& other) noexcept: BaseComponent(std::move(other)),
                                                                        m_parent_(other.m_parent_)
    {
    }

    EngineComponent& EngineComponent::operator=(const EngineComponent& other)
    {
        if (this == &other)
            return *this;
        BaseComponent::operator =(other);
        m_parent_ = other.m_parent_;
        return *this;
    }

    EngineComponent& EngineComponent::operator=(EngineComponent&& other) noexcept
    {
        if (this == &other)
            return *this;
        BaseComponent::operator =(other);
        m_parent_ = other.m_parent_;
        return *this;
    }

    EngineComponent::EngineComponent(const EngineCore* parent): m_parent_(parent)
    {
    }

    EngineComponent::~EngineComponent()
    {
        m_parent_ = nullptr;
    }

    void EngineComponent::init(const EngineCore* parent)
    {
        m_parent_ = parent;
    }

}
