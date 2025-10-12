#pragma once

#include <cstdint>
#include <iterator>
#include <vector>

#include "Layer.hpp"

namespace Voxy {

class LayerStack {
public:
    LayerStack(const std::string &debugName);
    ~LayerStack();

    void PushLayer(ILayer *layer);
    void RemoveLayer(ILayer *layer);

    void PushOverlay(ILayer *overlay);
    void RemoveOverlay(ILayer *overlay);

    std::vector<ILayer *>::iterator begin() { return m_Layers.begin(); }
    std::vector<ILayer *>::iterator end() { return m_Layers.end(); }

    std::vector<ILayer *>::reverse_iterator rbegin() {
        return m_Layers.rbegin();
    }
    std::vector<ILayer *>::reverse_iterator rend() { return m_Layers.rend(); }

private:
    std::vector<ILayer *> m_Layers;
    size_t m_OverlaysBeginIdx = 0;
    std::string m_DebugName;
};

} // namespace Voxy