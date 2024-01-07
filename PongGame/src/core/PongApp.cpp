#include "PongApp.h"

std::shared_ptr<GE::EngineData> PongApp::GetData() const
{
    return std::make_shared<GE::EngineData>(1280, 720, "PongApp");
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
