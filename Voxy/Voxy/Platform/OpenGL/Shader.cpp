#include "Shader.h"

#include <glad/glad.h>

#include "Log.h"

namespace Voxy::OpenGL
{
    void LogCompileErrors(uint32_t id)
    {
        GLint hasCompiled;
        glGetShaderiv(id, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_TRUE)
            return;

        GLsizei logLength = 0;
        GLchar message[1024];
        glGetShaderInfoLog(id, 1024, &logLength, message);

        VOXY_CORE_ERROR("Failed to compile shader: {}", (char *)message);
    }

    void LogLinkingErrors(uint32_t id)
    {
        GLint hasLinked;
        glGetProgramiv(id, GL_LINK_STATUS, &hasLinked);
        if (hasLinked == GL_TRUE)
            return;

        GLsizei logLength = 0;
        GLchar message[1024];
        glGetProgramInfoLog(id, 1024, &logLength, message);

        VOXY_CORE_ERROR("Failed to link shaders: {}", (char *)message);
    }

    Shader::Shader(const std::string &vertexSource, const std::string &fragmentSource)
    {
        const char *vsSource = vertexSource.c_str();
        GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vshader, 1, &vsSource, NULL);
        glCompileShader(vshader);
        LogCompileErrors(vshader);

        const char *fsSource = vertexSource.c_str();
        GLuint fshader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(fshader, 1, &fsSource, NULL);
        glCompileShader(fshader);
        LogCompileErrors(vshader);

        m_ID = glCreateProgram();
        glAttachShader(m_ID, vshader);
        glAttachShader(m_ID, vshader);
        glLinkProgram(m_ID);
        LogLinkingErrors(m_ID);

        glDetachShader(m_ID, vshader);
        glDetachShader(m_ID, fshader);

        glDeleteShader(vshader);
        glDeleteShader(fshader);
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_ID);
    }

    void Shader::Bind() const
    {
        glUseProgram(m_ID);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }
}