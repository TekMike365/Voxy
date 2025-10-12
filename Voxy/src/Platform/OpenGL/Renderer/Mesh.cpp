#include "Mesh.hpp"

#include <glad/glad.h>

#include "Log.hpp"

namespace Voxy::Renderer {

Ref<Mesh> Create(const Ref<Buffer> &indexBuffer) {
    return std::make_shared<OpenGL_Mesh>(indexBuffer);
}

inline GLenum GetGLType(ShaderType type) {
    switch (GetSTtype(type)) {
    case STint:
        return GL_INT;
    case STuint:
        return GL_UNSIGNED_INT;
    case STfloat:
        return GL_FLOAT;
    }

    VoxyAssert(0, "Unknown Shader Type");
    return -1;
}

OpenGL_Mesh::OpenGL_Mesh(const Ref<Buffer> &indexBuffer)
    : m_IndexBuffer(indexBuffer) {
    VoxyAssert(indexBuffer->GetType() == Renderer::BufferType::Index,
               "Buffer isn't of type Index buffer");

    glGenVertexArrays(1, &m_ID);
    glBindVertexArray(m_ID);
    m_IndexBuffer->Bind();
    Unbind();
    m_IndexBuffer->Unbind();
}

OpenGL_Mesh::~OpenGL_Mesh() { glDeleteVertexArrays(1, &m_ID); }

void OpenGL_Mesh::Bind() const { glBindVertexArray(m_ID); }

void OpenGL_Mesh::Unbind() const { glBindVertexArray(0); }

void OpenGL_Mesh::AddObject(size_t pointer, size_t indexCount,
                            const std::string &name) {
    m_Objects[name] = {pointer, indexCount};
}

Mesh::Object &OpenGL_Mesh::GetObject(const std::string &name) {
    return m_Objects.at(name);
}

void OpenGL_Mesh::AddAttribute(const VertexAttribute &attrib) {
    using namespace Renderer;

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

} // namespace Voxy::Renderer