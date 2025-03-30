#include "VertexArray.h"

#include <glad/glad.h>

#include "Log.h"

namespace Voxy::OpenGL
{
    inline GLenum GetGLType(Renderer::ShaderType type)
    {
        switch (Renderer::GetSTtype(type))
        {
        case Renderer::STint:
            return GL_INT;
        case Renderer::STuint:
            return GL_UNSIGNED_INT;
        case Renderer::STfloat:
            return GL_FLOAT;
        }

        VOXY_ASSERT(0, "Unknown Shader Type");
        return -1;
    }

    VertexArray::VertexArray(const Ref<Buffer> &indexBuffer)
        : m_IndexBuffer(indexBuffer)
    {
        VOXY_ASSERT(indexBuffer->GetType() == Renderer::BufferType::Index, "Buffer isn't of type Index buffer")

        glGenVertexArrays(1, &m_ID);
        glBindVertexArray(m_ID);
        m_IndexBuffer->Bind();
        Unbind();
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_ID);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(m_ID);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void VertexArray::AddObject(size_t pointer, size_t indexCount, const std::string &name)
    {
        m_Objects[name] = {pointer, indexCount};
    }

    VertexArray::Object &VertexArray::GetObject(const std::string &name)
    {
        return m_Objects.at(name);
    }

    void VertexArray::AddAttribute(const VertexAttribute &element)
    {
        using namespace Renderer;

        m_VertexElements.emplace_back(element);

        Bind();
        element.Buffer->Bind();

        glEnableVertexAttribArray(element.Index);
        if (GetSTtype(element.Type) == STfloat || element.Normalised)
            glVertexAttribPointer(element.Index, GetSTcount(element.Type), GetGLType(element.Type), element.Normalised, element.Stride, (void *)element.Pointer);
        else
            glVertexAttribIPointer(element.Index, GetSTcount(element.Type), GetGLType(element.Type), element.Stride, (void *)element.Pointer);

        element.Buffer->Unbind();
        Unbind();
    }
}