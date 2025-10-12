#include "OpenGL.hpp"
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <sstream>

#include "Log.hpp"

bool g_IsInitialized = false;

// Yoinked from: https://learnopengl.com/In-Practice/Debugging
void GLAPIENTRY GLErrorMsgCallback(GLenum source, GLenum type, GLuint id,
                                   GLenum severity, GLsizei length,
                                   const GLchar *message,
                                   const void *userParam) {
    // ignore non-significant error/warning codes
    if (id == 131169 || id == 131185 || id == 131218 || id == 131204)
        return;

    std::stringstream ss;

    ss << "OpenGL (" << id << "): " << message << std::endl;

    switch (source) {
    case GL_DEBUG_SOURCE_API:
        ss << "Source: API";
        break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        ss << "Source: Window System";
        break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        ss << "Source: Shader Compiler";
        break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:
        ss << "Source: Third Party";
        break;
    case GL_DEBUG_SOURCE_APPLICATION:
        ss << "Source: Application";
        break;
    case GL_DEBUG_SOURCE_OTHER:
        ss << "Source: Other";
        break;
    }
    ss << std::endl;

    switch (type) {
    case GL_DEBUG_TYPE_ERROR:
        ss << "Type: Error";
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        ss << "Type: Deprecated Behaviour";
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        ss << "Type: Undefined Behaviour";
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        ss << "Type: Portability";
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        ss << "Type: Performance";
        break;
    case GL_DEBUG_TYPE_MARKER:
        ss << "Type: Marker";
        break;
    case GL_DEBUG_TYPE_PUSH_GROUP:
        ss << "Type: Push Group";
        break;
    case GL_DEBUG_TYPE_POP_GROUP:
        ss << "Type: Pop Group";
        break;
    case GL_DEBUG_TYPE_OTHER:
        ss << "Type: Other";
        break;
    }
    ss << std::endl;

    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:
        ss << "Severity: high";
        VoxyCoreError(ss.str());
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        ss << "Severity: medium";
        VoxyCoreWarn(ss.str());
        break;
    case GL_DEBUG_SEVERITY_LOW:
        ss << "Severity: low";
        VoxyCoreInfo(ss.str());
        break;
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        ss << "Severity: notification";
        VoxyCoreTrace(ss.str());
        break;
    }
}

namespace Voxy::Platform {

void OpenGL_Init() {
    if (g_IsInitialized)
        return;

    VoxyAssert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress),
               "GLAD: Failed to load OpenGL");
    g_IsInitialized = true;

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(GLErrorMsgCallback, 0);
}

} // namespace Voxy::Platform
