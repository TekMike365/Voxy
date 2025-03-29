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

    uint32_t VertexArray::AddElement(const VertexElement &element)
    {
        using namespace Renderer;

        m_VertexElements.emplace_back(element);
        uint32_t idx = m_VertexElements.size() - 1;

        Bind();
        element.Buffer->Bind();

        glEnableVertexAttribArray(element.Index);
        if (GetSTtype(element.Type) == STfloat || element.Normalised)
            glVertexAttribPointer(element.Index, GetSTcount(element.Type), GetGLType(element.Type), element.Normalised, element.Stride, (void *)element.Pointer);
        else
            glVertexAttribIPointer(element.Index, GetSTcount(element.Type), GetGLType(element.Type), element.Stride, (void *)element.Pointer);

        element.Buffer->Unbind();
        Unbind();

        return idx;
    }

    void VertexArray::RemoveElement(uint32_t index)
    {
        using namespace Renderer;

        const VertexElement &element = m_VertexElements.at(index);

        Bind();
        element.Buffer->Bind();

        glDisableVertexAttribArray(element.Index);

        element.Buffer->Unbind();
        Unbind();

        m_VertexElements.erase(m_VertexElements.begin() + index);
    }

    Renderer::VertexElement &VertexArray::GetElement(uint32_t index)
    {
        return m_VertexElements.at(index);
    }
}