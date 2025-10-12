#include "LayerStack.hpp"

#include "Log.hpp"

namespace Voxy {

LayerStack::LayerStack(const std::string &debugName) : m_DebugName(debugName) {}

LayerStack::~LayerStack() {
    VoxyCoreTrace("{}: deleting layers...", m_DebugName);

    for (Layer *layer : m_Layers)
        if (layer) {
            layer->OnDetach();
            VoxyCoreTrace("{}: '{}' deleted", m_DebugName,
                          layer->GetDebugName());
            delete layer;
        }
}

void LayerStack::PushLayer(Layer *layer) {
    m_Layers.insert(m_Layers.begin() + m_OverlaysBeginIdx++, layer);
    layer->OnAttach();
    VoxyCoreTrace("{}: '{}' added", m_DebugName, layer->GetDebugName());
}

void LayerStack::RemoveLayer(Layer *layer) {
    auto end = m_Layers.begin() + m_OverlaysBeginIdx;
    auto it = std::find(m_Layers.begin(), end, layer);

    if (it == end)
        return;

    (*it)->OnDetach();
    m_Layers.erase(it);
    m_OverlaysBeginIdx--;

    VoxyCoreTrace("{}: '{}' removed", m_DebugName, layer->GetDebugName());
}

void LayerStack::PushOverlay(Layer *overlay) {
    m_Layers.push_back(overlay);
    overlay->OnAttach();
    VoxyCoreTrace("{}: '{}' added", m_DebugName, overlay->GetDebugName());
}

void LayerStack::RemoveOverlay(Layer *overlay) {
    auto begin = m_Layers.begin() + m_OverlaysBeginIdx;
    auto it = std::find(begin, m_Layers.end(), overlay);

    if (it == m_Layers.end())
        return;

    (*it)->OnDetach();
    m_Layers.erase(it);
    VoxyCoreTrace("{}: '{}' removed", m_DebugName, overlay->GetDebugName());
}

} // namespace Voxy