#pragma once

#include "Helpers.hpp"

#include <imgui.h>

namespace Voxy {

class ImGuiManager {
public:
    static void Init();
    static void Terminate();

    static void BeginFrame();
    static void EndFrame(); // prepares draw data
    static ImDrawData *GetDrawData();

    static ImGuiManager &Get() { return *s_Instance; }

private:
    static URef<ImGuiManager> s_Instance;
};

} // namespace Voxy
