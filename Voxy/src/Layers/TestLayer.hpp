#pragma once

#include <imgui.h>

#include "Layer.hpp"

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
