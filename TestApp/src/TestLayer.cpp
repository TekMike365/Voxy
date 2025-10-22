#include "TestLayer.hpp"

#include "Core/Application.hpp"

void TestLayer::DisplayOverlay() {
    const ImGuiViewport *viewport = ImGui::GetMainViewport();
    ImVec2 workPos = viewport->WorkPos; // Top-left
    ImVec2 workSize = viewport->WorkSize;

    ImVec2 windowPos = ImVec2(workPos.x + workSize.x, workPos.y); // Top-right
    ImVec2 windowPosPivot = ImVec2(1.0f, 0.0f);                   // Top-right

    ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always, windowPosPivot);
    ImGui::SetNextWindowBgAlpha(0.65f);

    ImGuiWindowFlags windowFlags =
        ImGuiWindowFlags_NoDecoration |       // No title bar, resize borders,
                                              // etc.
        ImGuiWindowFlags_AlwaysAutoResize |   // Window size adjusts to
                                              // content
        ImGuiWindowFlags_NoSavedSettings |    // Don't save settings (pos,
                                              // size) to the ini file
        ImGuiWindowFlags_NoFocusOnAppearing | // Don't steal focus
        ImGuiWindowFlags_NoNav | // Disable keyboard/gamepad navigation
        ImGuiWindowFlags_NoMove;

    ImGui::Begin("Overlay", nullptr, windowFlags);
    ImGui::Text("Frame: %.3f ms (%.1f FPS)", m_DT.Miliseconds(),
                1.0f / m_DT.Seconds());
    ImGui::End();
}

void TestLayer::SetupDemo() {

    const float g_Vertices[] = {
        0.0f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, // endl
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // endl
        0.5f,  -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // endl

        0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, // endl
        0.0f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, // endl
        1.0f,  0.5f,  0.0f, 1.0f, 1.0f, 0.0f, // endl
    };

    const float g_Offsets[] = {
        -0.5f, 0.0f, 0.0f, // endl
        0.5f,  0.0f, 0.0f, // endl
    };

    const uint32_t g_Indices[] = {
        0, 1, 2, // endl
        3, 4, 5  // endl
    };

    const char *g_VertexSource = R"(
            #version 430 core

            layout (location = 0) in vec3 aPos;
            layout (location = 1) in vec3 aColor;
            layout (location = 2) in vec3 aOffset;

            uniform mat4 uVP;

            out vec3 vColor;

            void main()
            {
                vColor = aColor;
                gl_Position = uVP * vec4(aPos + aOffset, 1.0);
            }
        )";

    const char *g_FragmentSource = R"(
            #version 430 core

            in vec3 vColor;
            out vec4 fColor;

            void main()
            {
                fColor = vec4(vColor, 1.0);
            }
        )";

    using namespace Renderer;

    m_Renderer = Application::GetInstance()
                     ->GetWindow()
                     ->GetGraphicsContext()
                     ->GetRenderer();

    m_VertexBuffer =
        Buffer::Create(BufferType::Vertex, sizeof(g_Vertices), g_Vertices);
    m_IndexBuffer =
        Buffer::Create(BufferType::Index, sizeof(g_Indices), g_Indices);

    m_OffsetsBuffer =
        Buffer::Create(BufferType::Vertex, sizeof(g_Offsets), g_Offsets);

    m_VertexArray = VertexArray::Create(m_IndexBuffer);
    m_VertexArray->AddObject(0, 3, "triangle");
    m_VertexArray->AddObject(3, 3, "inversedTriangle");
    m_VertexArray->AddAttribute(
        VertexAttribute(0, STfloat3, 0, 24, m_VertexBuffer));
    m_VertexArray->AddAttribute(
        VertexAttribute(1, STfloat3, 12, 24, m_VertexBuffer));
    m_VertexArray->AddAttribute(
        VertexAttribute(2, STfloat3, 0, 12, m_OffsetsBuffer, 1));

    m_Shader = Shader::Create(g_VertexSource, g_FragmentSource);

    m_Transform.pos = glm::vec3(0.25f, 0.0f, 0.0f);
}

void TestLayer::RenderDemo() {
    m_Renderer->SubmitVertexArray(m_VertexArray, m_Shader, "triangle",
                                  m_Transform, 2);
    m_Renderer->SubmitVertexArray(m_VertexArray, m_Shader, "inversedTriangle",
                                  m_Transform);
}
