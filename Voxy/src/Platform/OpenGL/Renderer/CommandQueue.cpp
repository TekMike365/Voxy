#include "CommandQueue.hpp"

#include "Log.hpp"

namespace Voxy::Renderer {

void OpenGL_CommandQueue::PushDrawVertexArrayCommand(
    const OpenGL_DrawVertexArrayCommand &cmd) {
    m_CommandQ.Push(RenderCommand::DrawVertexArray);
    m_DrawVertexArrayQ.Push(cmd);
}

void OpenGL_CommandQueue::Flush() {
    while (!m_CommandQ.IsEmpty()) {
        switch (*m_CommandQ.Pop()) {
        case RenderCommand::DrawVertexArray:
            VoxyAssert(!m_DrawVertexArrayQ.IsEmpty(),
                       "This shouldn't happen (I think).");
            m_DrawVertexArrayQ.Pop()->Execute();
            break;
        default:
            break;
        }
    }

    // This feels ugly
    m_CommandQ.Clear();
    m_DrawVertexArrayQ.Clear();
}

} // namespace Voxy::Renderer
