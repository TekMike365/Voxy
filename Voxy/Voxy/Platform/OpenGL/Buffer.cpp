#include "Buffer.h"

#include <glad/glad.h>

#include "Log.h"

namespace Voxy::OpenGL
{
    inline GLenum GetGLType(Renderer::BufferType type)
    {
        switch (type)
        {
        case Renderer::BufferType::Vertex:
            return GL_ARRAY_BUFFER;
        case Renderer::BufferType::Index:
            return GL_ELEMENT_ARRAY_BUFFER;
        }

        VOXY_ASSERT(0, "Unknown Buffer Type");
        return -1;
    }

    Buffer::Buffer(Renderer::BufferType type, size_t size, const void *data)
        : m_Type(type)
    {
        glGenBuffers(1, &m_ID);
        glBindBuffer(GetGLType(m_Type), m_ID);
        glBufferData(GetGLType(m_Type), size, data, GL_STATIC_DRAW);
        Unbind();
    }

    Buffer::~Buffer()
    {
        glDeleteBuffers(1, &m_ID);
    }

    void Buffer::Bind() const
    {
        glBindBuffer(GetGLType(m_Type), m_ID);
    }

    void Buffer::Unbind() const
    {
        glBindBuffer(GetGLType(m_Type), 0);
    }
}