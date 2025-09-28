#pragma once

#include "Layer.hpp"
#include <imgui.h>

namespace Voxy {

class TestLayer : public Layer {
public:
    virtual void OnAttach() override {}

    virtual void OnDetach() override {}

    virtual void OnUpdate() override {
        // 1. Show the big demo window (Most of the sample code is in
        // ImGui::ShowDemoWindow()! You can browse its code to learn more
        // about Dear ImGui!).
        if (m_ShowDemoWindow)
            ImGui::ShowDemoWindow(&m_ShowDemoWindow);

        // 2. Show a simple window that we create ourselves. We use a
        // Begin/End pair to create a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!"); // Create a window called "Hello,
                                           // world!" and append into it.

            ImGui::Text(
                "This is some useful text."); // Display some text (you can
                                              // use a format strings too)
            ImGui::Checkbox("Demo Window",
                            &m_ShowDemoWindow); // Edit bools storing our
                                                // window open/close state
            ImGui::Checkbox("Another Window", &m_ShowAnotherWindow);

            ImGui::SliderFloat(
                "float", &f, 0.0f,
                1.0f); // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3(
                "clear color",
                (float *)&m_Color); // Edit 3 floats representing a color

            if (ImGui::Button(
                    "Button")) // Buttons return true when clicked (most
                               // widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (m_ShowAnotherWindow) {
            ImGui::Begin(
                "Another Window",
                &m_ShowAnotherWindow); // Pass a pointer to our bool
                                       // variable (the window will have a
                                       // closing button that will clear the
                                       // bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                m_ShowAnotherWindow = false;
            ImGui::End();
        }
    }

    virtual bool OnEvent(Event &e) override { return false; }

private:
    // Our state
    bool m_ShowDemoWindow = true;
    bool m_ShowAnotherWindow = false;
    ImVec4 m_Color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};

} // namespace Voxy
