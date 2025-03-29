#pragma once

#include <vector>

#include "Voxy/Renderer/VertexArray.h"

namespace Voxy::OpenGL
{
    class VertexArray : public Renderer::VertexArray
    {
        using Buffer = Renderer::Buffer;
        using VertexElement = Renderer::VertexElement;

    public:
        VertexArray(const Ref<Buffer> &indexBuffer);
        ~VertexArray();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual uint32_t AddElement(const VertexElement &element) override;
        virtual void RemoveElement(uint32_t index) override;
        virtual VertexElement &GetElement(uint32_t index) override;

        inline virtual const Ref<Buffer> &GetIndexBuffer() const override { return m_IndexBuffer; }

    private:
        uint32_t m_ID;
        Ref<Buffer> m_IndexBuffer;
        std::vector<VertexElement> m_VertexElements;
    };
}