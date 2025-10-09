#pragma once

#include <cstdint>
#include <iterator>
#include <vector>

#include "Layer.hpp"

namespace Voxy {

class LayerStack {
public:
    ~LayerStack();

    void PushLayer(Layer *layer);
    void RemoveLayer(Layer *layer);

    void PushOverlay(Layer *overlay);
    void RemoveOverlay(Layer *overlay);

    std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
    std::vector<Layer *>::iterator end() { return m_Layers.end(); }

    std::vector<Layer *>::reverse_iterator rbegin() {
        return m_Layers.rbegin();
    }
    std::vector<Layer *>::reverse_iterator rend() { return m_Layers.rend(); }

private:
    std::vector<Layer *> m_Layers;
    size_t m_OverlaysBeginIdx = 0;
};

} // namespace Voxy