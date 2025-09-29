#pragma once

#include "Layer.hpp"
#include <imgui.h>

namespace Voxy {

class TestLayer : public Layer {
public:
    virtual void OnAttach() override {}

    virtual void OnDetach() override {}

    virtual void OnUpdate() override { ImGui::ShowDemoWindow(); }

    virtual bool OnEvent(Event &e) override { return false; }

private:
};

} // namespace Voxy
