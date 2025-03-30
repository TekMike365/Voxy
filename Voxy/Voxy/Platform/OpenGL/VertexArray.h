#pragma once

#include <vector>
#include <unordered_map>
#include <string>

#include "Voxy/Renderer/VertexArray.h"

namespace Voxy::OpenGL
{
    class VertexArray : public Renderer::VertexArray
    {
        using Buffer = Renderer::Buffer;
        using VertexAttribute = Renderer::VertexAttribute;

    public:
        VertexArray(const Ref<Buffer> &indexBuffer);
        ~VertexArray();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual void AddObject(size_t pointer, size_t indexCount, const std::string &name) override;
        virtual Object &GetObject(const std::string &name) override;
        virtual void AddAttribute(const VertexAttribute &element) override;

        inline virtual const Ref<Buffer> &GetIndexBuffer() const override { return m_IndexBuffer; }

    private:
        uint32_t m_ID;
        Ref<Buffer> m_IndexBuffer;
        std::vector<VertexAttribute> m_VertexElements;
        std::unordered_map<std::string, Object> m_Objects;
    };
}