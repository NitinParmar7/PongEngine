#pragma once
#include "core/engine/Engine.h"

class PongApp final : public GE::EngineCore
{
public:
    PongApp(const PongApp& other) = delete;

    PongApp(PongApp&& other) noexcept = delete;

    PongApp& operator=(const PongApp& other) = delete;

    PongApp& operator=(PongApp&& other) noexcept = delete;


#pragma region EngineCore
    [[nodiscard]] std::shared_ptr<GE::EngineData> GetData() const override;

    void init() override;
    void exit() override;

#pragma endregion

    ~PongApp() override;


private:

    PongApp() = default;
};



std::shared_ptr<GE::EngineCore> GE::create_engine()
{
    return EngineCore::get<PongApp>();
}
