#pragma once

#include "Voxy.h"
#include "Application.h"

extern Voxy::Application *Voxy::CreateApplication();

int main()
{
    Voxy::Init();

    auto *app = Voxy::CreateApplication();
    app->Run();
    delete app;

    Voxy::Shutdown();
}