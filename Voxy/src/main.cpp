#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "platform/GLFW/GLFW.hpp"
#include "platform/GLFW/GLFW_Window.hpp"

int main(void) {
    Voxy::Platform::GLFW_Init();

    auto wnd = Voxy::Window::Create();

    /* Make the window's context current */
    glfwMakeContextCurrent((GLFWwindow *)wnd->GetHandle());

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose((GLFWwindow *)wnd->GetHandle())) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers((GLFWwindow *)wnd->GetHandle());

        /* Poll for and process events */
        glfwPollEvents();
    }

    Voxy::Platform::GLFW_Terminate();
}
