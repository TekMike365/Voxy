#include "VertexArray.hpp"

#include <glad/glad.h>

#include "Log.hpp"

namespace Voxy::Renderer {

Ref<VertexArray> VertexArray::Create(const Ref<Buffer> &indexBuffer) {
    return std::make_shared<OpenGL_VertexArray>(indexBuffer);
}

inline GLenum GetGLType(ShaderType type) {
    switch (GetSTtype(type)) {
    case STint:
        return GL_INT;
    case STuint:
        return GL_UNSIGNED_INT;
    case STfloat:
        return GL_FLOAT;
    default:
        VoxyAssert(0, "Unknown Shader Type");
        return -1;
    }
}

OpenGL_VertexArray::OpenGL_VertexArray(const Ref<Buffer> &indexBuffer)
    : m_IndexBuffer(indexBuffer) {
    VoxyAssert(indexBuffer->GetType() == Renderer::BufferType::Index,
               "Buffer isn't of type Index buffer");

    glGenVertexArrays(1, &m_ID);
    glBindVertexArray(m_ID);
    m_IndexBuffer->Bind();
    Unbind();
    m_IndexBuffer->Unbind();
}

OpenGL_VertexArray::~OpenGL_VertexArray() { glDeleteVertexArrays(1, &m_ID); }

void OpenGL_VertexArray::AddObject(size_t pointer, size_t indexCount,
                                   const std::string &name) {
    m_Objects[name] = {pointer, indexCount};
}

VertexArray::Object &OpenGL_VertexArray::GetObject(const std::string &name) {
    return m_Objects.at(name);
}

void OpenGL_VertexArray::AddAttribute(const VertexAttribute &attrib) {
    Bind();
    attrib.buffer->Bind();

    glEnableVertexAttribArray(attrib.index);
    glVertexAttribDivisor(attrib.index, attrib.divisor);
    if (GetSTtype(attrib.type) == STfloat || attrib.normalised)
        glVertexAttribPointer(attrib.index, GetSTcount(attrib.type),
                              GetGLType(attrib.type), attrib.normalised,
                              attrib.stride, (void *)attrib.pointer);
    else
        glVertexAttribIPointer(attrib.index, GetSTcount(attrib.type),
                               GetGLType(attrib.type), attrib.stride,
                               (void *)attrib.pointer);

    attrib.buffer->Unbind();
    Unbind();
}

void OpenGL_VertexArray::Bind() const { glBindVertexArray(m_ID); }

void OpenGL_VertexArray::Unbind() const { glBindVertexArray(0); }

} // namespace Voxy::Renderer