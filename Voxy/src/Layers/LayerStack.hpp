#pragma once

#include <cstdint>
#include <iterator>
#include <vector>

#include "Helpers.hpp"
#include "Layer.hpp"
#include "Log.hpp"

namespace Voxy {

class LayerStack {
    using LayerVec = std::vector<URef<Layer>>;

public:
    LayerStack(const std::string &debugName);

    template <typename T> void AddLayer();
    template <typename T> void AddOverlay();

    LayerVec::iterator begin() { return m_Layers.begin(); }
    LayerVec::iterator end() { return m_Layers.end(); }
    LayerVec::reverse_iterator rbegin() { return m_Layers.rbegin(); }
    LayerVec::reverse_iterator rend() { return m_Layers.rend(); }

private:
    LayerVec m_Layers;
    size_t m_OverlaysOffset = 0;
    std::string m_DebugName;
};

template <typename T> inline void LayerStack::AddLayer() {
    Layer *layer = new T();
    m_Layers.emplace(begin() + (m_OverlaysOffset++), layer);
    layer->OnAttach();
    VoxyCoreTrace("{}: added new layer '{}'", m_DebugName,
                  layer->GetDebugName());
}

template <typename T> inline void LayerStack::AddOverlay() {
    Layer *overlay = new T();
    m_Layers.emplace_back(overlay);
    overlay->OnAttach();
    VoxyCoreTrace("{}: added new overlay '{}'", m_DebugName,
                  overlay->GetDebugName());
}

} // namespace Voxy