#include "CommandQueue.hpp"

#include "Log.hpp"

namespace Voxy::Renderer {

void OpenGL_CommandQueue::PushDrawMeshCommand(
    const OpenGL_DrawMeshCommand &cmd) {
    m_CommandQ.Push(RenderCommand::DrawMesh);
    m_DrawMeshQ.Push(cmd);
}

void OpenGL_CommandQueue::Flush() {
    while (!m_CommandQ.IsEmpty()) {
        switch (*m_CommandQ.Pop()) {
        case RenderCommand::DrawMesh:
            VoxyAssert(!m_DrawMeshQ.IsEmpty(),
                       "This shouldn't happen (I think).");
            m_DrawMeshQ.Pop()->Execute();
            break;
        default:
            break;
        }
    }

    // This feels ugly
    m_CommandQ.Clear();
    m_DrawMeshQ.Clear();
}

} // namespace Voxy::Renderer
