#pragma once

#include "Helpers.hpp"
#include "Window.hpp"

namespace Voxy::Platform {

void Init();
void Terminate();

Ref<IWindow> CreateWindow(const WindowParams &params = WindowParams());

void BeginImGuiFrame();

} // namespace Voxy::Platform
