#include "Shader.hpp"

#include <glad/glad.h>

#include "Log.hpp"
#include <glm/gtc/type_ptr.hpp>

namespace Voxy::Renderer {

static Ref<Shader> Create(const std::string &vertexSource,
                          const std::string &fragmentSource) {
    return std::make_shared<OpenGL_Shader>(vertexSource, fragmentSource);
}

void LogCompileErrors(uint32_t id) {
    GLint hasCompiled;
    glGetShaderiv(id, GL_COMPILE_STATUS, &hasCompiled);
    if (hasCompiled == GL_TRUE)
        return;

    GLsizei logLength = 0;
    GLchar message[1024];
    glGetShaderInfoLog(id, 1024, &logLength, message);

    VoxyCoreError("Failed to compile shader: {}", (char *)message);
}

void LogLinkingErrors(uint32_t id) {
    GLint hasLinked;
    glGetProgramiv(id, GL_LINK_STATUS, &hasLinked);
    if (hasLinked == GL_TRUE)
        return;

    GLsizei logLength = 0;
    GLchar message[1024];
    glGetProgramInfoLog(id, 1024, &logLength, message);

    VoxyCoreError("Failed to link shaders: {}", (char *)message);
}

OpenGL_Shader::OpenGL_Shader(const std::string &vertexSource,
                             const std::string &fragmentSource) {
    const char *vsSource = vertexSource.c_str();
    GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vshader, 1, &vsSource, NULL);
    glCompileShader(vshader);
    LogCompileErrors(vshader);

    const char *fsSource = fragmentSource.c_str();
    GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fshader, 1, &fsSource, NULL);
    glCompileShader(fshader);
    LogCompileErrors(fshader);

    m_ID = glCreateProgram();
    glAttachShader(m_ID, vshader);
    glAttachShader(m_ID, fshader);
    glLinkProgram(m_ID);
    LogLinkingErrors(m_ID);

    glDetachShader(m_ID, vshader);
    glDetachShader(m_ID, fshader);

    glDeleteShader(vshader);
    glDeleteShader(fshader);

    // Store uniform locations
    GLint uniformCount = 0;
    glGetProgramiv(m_ID, GL_ACTIVE_UNIFORMS, &uniformCount);
    for (GLint idx = 0; idx < uniformCount; idx++) {
        GLint size = 0;
        GLenum type = 0;
        GLchar buff[1024];
        glGetActiveUniform(m_ID, idx, 1024, NULL, &size, &type, buff);

        m_UniformLocationMap[(char *)buff] = (int32_t)idx;
    }
}

OpenGL_Shader::~OpenGL_Shader() { glDeleteProgram(m_ID); }

void OpenGL_Shader::Bind() const { glUseProgram(m_ID); }

void OpenGL_Shader::Unbind() const { glUseProgram(0); }

void OpenGL_Shader::UploadUniform(const glm::mat4 &mat,
                                  const std::string &name) const {
    int32_t location = m_UniformLocationMap.at(name);
    glUniformMatrix4fv(location, 1, false, glm::value_ptr(mat));
}

} // namespace Voxy::Renderer