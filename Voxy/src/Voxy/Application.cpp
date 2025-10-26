#include "Application.hpp"

#include <GLFW/glfw3.h>

namespace Voxy {

Application::Application() {}

Application::~Application() {}

void Application::Run() {
    GLFWwindow *window;
    GLFWwindow *window2;

    /* Initialize the library */
    if (!glfwInit())
        return;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return;
    }

    window2 = glfwCreateWindow(640, 480, "Hello World #2", NULL, NULL);
    if (!window2) {
        glfwTerminate();
        return;
    }

    bool running = true;
    /* Loop until the user closes the window */
    while (running) {
        bool quit = true;

        glfwMakeContextCurrent(window);
        if (!glfwWindowShouldClose(window))
            quit = false;
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();

        glfwMakeContextCurrent(window2);
        if (!glfwWindowShouldClose(window2))
            quit = false;
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();

        running = !quit;
    }

    glfwTerminate();
}

} // namespace Voxy
