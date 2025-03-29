#pragma once

#include "Helpers.h"
#include "Buffer.h"

#define _CREATE_TYPE(idx, size, count) ((size * count) << 6) | (idx << 2) | (count - 1)

namespace Voxy::Renderer
{
    enum ShaderType
    {
        STnone = 0,

        STint = _CREATE_TYPE(1, sizeof(int32_t), 1),
        STint2 = _CREATE_TYPE(STint, sizeof(int32_t), 2),
        STint3 = _CREATE_TYPE(STint, sizeof(int32_t), 3),
        STint4 = _CREATE_TYPE(STint, sizeof(int32_t), 4),

        STuint = _CREATE_TYPE(2, sizeof(int32_t), 1),
        STuint2 = _CREATE_TYPE(STuint, sizeof(int32_t), 2),
        STuint3 = _CREATE_TYPE(STuint, sizeof(int32_t), 3),
        STuint4 = _CREATE_TYPE(STuint, sizeof(int32_t), 4),

        STfloat = _CREATE_TYPE(3, sizeof(int32_t), 1),
        STfloat2 = _CREATE_TYPE(STfloat, sizeof(int32_t), 2),
        STfloat3 = _CREATE_TYPE(STfloat, sizeof(int32_t), 3),
        STfloat4 = _CREATE_TYPE(STfloat, sizeof(int32_t), 4),
    };

    inline ShaderType GetSTtype(ShaderType type) { return (ShaderType)(type & (~0b11)); }
    inline uint32_t GetSTcount(ShaderType type) { return type & 0b11; }
    inline uint32_t GetSTsize(ShaderType type) { return type & (~0b111111); };

    struct VertexElement
    {
    private:
        using BufferRef = Ref<Renderer::Buffer>;

    public:
        ShaderType Type = STnone;
        uint32_t Index = 0;
        size_t Stride = 0;
        size_t Pointer = 0;
        uint32_t Divisor = 0;
        bool Normalised = false;
        BufferRef Buffer = nullptr;

        VertexElement() = default;
        VertexElement(ShaderType type, uint32_t Index, size_t stride, size_t pointer, const BufferRef &buffer, uint32_t divisor = 0, bool normalised = false)
            : Type(type), Stride(stride), Pointer(pointer), Buffer(buffer), Divisor(divisor), Normalised(normalised) {}
    };

    // TODO: test
    class VertexArray
    {
    public:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual uint32_t AddElement(const VertexElement &element) = 0;
        virtual void RemoveElement(uint32_t index) = 0;
        virtual VertexElement &GetElement(uint32_t index) = 0;
        virtual const Ref<Buffer> &GetIndexBuffer() const = 0;

        static Ref<VertexArray> Create(const Ref<Buffer> &indexBuffer);
    };
}
