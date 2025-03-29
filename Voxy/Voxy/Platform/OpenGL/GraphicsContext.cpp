#include "GraphicsContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Voxy/IWindow.h"

#include "Log.h"

namespace Voxy::OpenGL
{
    GraphicsContext::GraphicsContext(const Ref<IWindow> &window)
        : m_Window(window)
    {
        // TODO: More windows
    }

    void GraphicsContext::MakeCurrent() const
    {
        // Switch based on Platform
        glfwMakeContextCurrent((GLFWwindow *)m_Window->GetWindowHandle());

        VOXY_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Glad couldn't be initialised.")
    }

    void GraphicsContext::SwapBuffers() const
    {
        // Switch based on Platform
        glfwSwapBuffers((GLFWwindow *)m_Window->GetWindowHandle());
    }

    void GraphicsContext::SetViewport(int32_t x, int32_t y, size_t width, size_t height) const
    {
        glViewport(x, y, width, height);
    }
}
