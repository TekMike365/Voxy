#include "LayerStack.hpp"

namespace Voxy {

LayerStack::~LayerStack() {
    for (Layer *layer : m_Layers)
        if (layer) {
            layer->OnDetach();
            delete layer;
        }
}

void LayerStack::PushLayer(Layer *layer) {
    m_Layers.insert(m_Layers.begin() + m_OverlaysBeginIdx++, layer);
    layer->OnAttach();
}

void LayerStack::RemoveLayer(Layer *layer) {
    auto end = m_Layers.begin() + m_OverlaysBeginIdx;
    auto it = std::find(m_Layers.begin(), end, layer);

    if (it == end)
        return;

    (*it)->OnDetach();
    m_Layers.erase(it);
    m_OverlaysBeginIdx--;
}

void LayerStack::PushOverlay(Layer *overlay) {
    m_Layers.push_back(overlay);
    overlay->OnAttach();
}

void LayerStack::RemoveOverlay(Layer *overlay) {
    auto begin = m_Layers.begin() + m_OverlaysBeginIdx;
    auto it = std::find(begin, m_Layers.end(), overlay);

    if (it == m_Layers.end())
        return;

    (*it)->OnDetach();
    m_Layers.erase(it);
}

} // namespace Voxy