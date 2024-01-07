#include "PongApp.h"

std::shared_ptr<GE::EngineData> PongApp::GetData() const
{
   return std::make_shared<GE::EngineData>(1280,720, "PongApp");
}

unsigned PongApp::GetWidth() const
{
    return EngineCore::GetWidth();
}

unsigned PongApp::GetHeight() const
{
    return EngineCore::GetHeight();
}

void PongApp::init()
{
    EngineCore::init();
}

void PongApp::exit()
{
    EngineCore::exit();
}

PongApp::~PongApp()
= default;

std::string_view PongApp::GetTitle() const
{
    return EngineCore::GetTitle();
}

