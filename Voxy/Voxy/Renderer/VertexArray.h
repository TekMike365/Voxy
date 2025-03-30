#pragma once

#include "Helpers.h"
#include "Log.h"
#include "Buffer.h"

#define _CREATE_SHADER_TYPE(idx, size, count) ((size * count) << 6) | (idx << 2) | (count - 1)

namespace Voxy::Renderer
{
    enum ShaderType
    {
        STnone = 0,

        STint = _CREATE_SHADER_TYPE(1, sizeof(int32_t), 1),
        STint2 = _CREATE_SHADER_TYPE(STint, sizeof(int32_t), 2),
        STint3 = _CREATE_SHADER_TYPE(STint, sizeof(int32_t), 3),
        STint4 = _CREATE_SHADER_TYPE(STint, sizeof(int32_t), 4),

        STuint = _CREATE_SHADER_TYPE(2, sizeof(int32_t), 1),
        STuint2 = _CREATE_SHADER_TYPE(STuint, sizeof(int32_t), 2),
        STuint3 = _CREATE_SHADER_TYPE(STuint, sizeof(int32_t), 3),
        STuint4 = _CREATE_SHADER_TYPE(STuint, sizeof(int32_t), 4),

        STfloat = _CREATE_SHADER_TYPE(3, sizeof(int32_t), 1),
        STfloat2 = _CREATE_SHADER_TYPE(STfloat, sizeof(int32_t), 2),
        STfloat3 = _CREATE_SHADER_TYPE(STfloat, sizeof(int32_t), 3),
        STfloat4 = _CREATE_SHADER_TYPE(STfloat, sizeof(int32_t), 4),
    };

    inline ShaderType GetSTtype(ShaderType type) { return (ShaderType)(type & (~0b11)); }
    inline uint32_t GetSTcount(ShaderType type) { return type & 0b11; }
    inline uint32_t GetSTsize(ShaderType type) { return type & (~0b111111); };

    struct VertexAttribute
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

        VertexAttribute() = default;
        VertexAttribute(ShaderType type, uint32_t Index, size_t stride, size_t pointer, const BufferRef &buffer, uint32_t divisor = 0, bool normalised = false)
            : Type(type), Stride(stride), Pointer(pointer), Buffer(buffer), Divisor(divisor), Normalised(normalised)
        {
            VOXY_ASSERT(buffer->GetType() == BufferType::Vertex, "VertexAttribute only accepts VertexBuffer");
        }
    };

    class VertexArray
    {
    public:
        struct Object
        {
            size_t Pointer = 0;
            size_t IndexCount = 0;
        };

    public:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void AddObject(size_t pointer, size_t indexCount, const std::string &name) = 0;
        virtual Object &GetObject(const std::string &name) = 0;
        virtual void AddAttribute(const VertexAttribute &element) = 0;

        virtual const Ref<Buffer> &GetIndexBuffer() const = 0;

        static Ref<VertexArray> Create(const Ref<Buffer> &indexBuffer);
    };
}
