#include "Buffer.hpp"

#include <glad/glad.h>

#include "Log.hpp"

namespace Voxy::Renderer {

Ref<IBuffer> IBuffer::Create(BufferType type, size_t size, const void *data) {
    return Ref<IBuffer>(new OpenGL_Buffer(type, size, data));
}

inline GLenum GetGLType(BufferType type) {
    switch (type) {
    case BufferType::Vertex:
        return GL_ARRAY_BUFFER;
    case BufferType::Index:
        return GL_ELEMENT_ARRAY_BUFFER;
    }

    VoxyAssert(0, "Unknown Buffer Type");
    return -1;
}

OpenGL_Buffer::OpenGL_Buffer(BufferType type, size_t size, const void *data)
    : m_Type(type) {
    glGenBuffers(1, &m_ID);
    glBindBuffer(GetGLType(m_Type), m_ID);
    glBufferData(GetGLType(m_Type), size, data, GL_STATIC_DRAW);
}

OpenGL_Buffer::~OpenGL_Buffer() { glDeleteBuffers(1, &m_ID); }

void OpenGL_Buffer::Bind() const { glBindBuffer(GetGLType(m_Type), m_ID); }

void OpenGL_Buffer::Unbind() const { glBindBuffer(GetGLType(m_Type), 0); }

} // namespace Voxy::Renderer
