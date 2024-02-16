#pragma once

namespace GE {
    class BaseComponent // NOLINT(cppcoreguidelines-special-member-functions)
    {
    public:
        BaseComponent() = default;

        virtual ~BaseComponent() = default;

        virtual void update() = 0;

        virtual void end() = 0;
    };

}
