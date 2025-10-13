#pragma once

#include <vector>

#include "RenderCommands.hpp"

namespace Voxy::Renderer {

class OpenGL_CommandQueue {
public:
    void PushDrawMeshCommand(const OpenGL_DrawMeshCommand &cmd);
    void Flush();

private:
    enum class RenderCommand { None = 0, DrawMesh };

    template <typename T> class VectorQueue {
    public:
        inline void Push(const T &t) { m_Vec.emplace_back(t); }
        inline const T *Pop() {
            return IsEmpty() ? nullptr : &m_Vec[m_ReadIdx++];
        }
        inline void Clear() {
            m_Vec.clear();
            m_ReadIdx = 0;
        }

        inline bool IsEmpty() const { return m_ReadIdx == m_Vec.size(); }
        inline bool IsClear() const {
            return m_Vec.size() == 0 && m_ReadIdx == 0;
        }

    private:
        std::vector<T> m_Vec;
        size_t m_ReadIdx;
    };

private:
    VectorQueue<RenderCommand> m_CommandQ;
    VectorQueue<OpenGL_DrawMeshCommand> m_DrawMeshQ;
};

} // namespace Voxy::Renderer
