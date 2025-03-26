#pragma once

#include <vector>

#include "Helpers.h"
#include "Layer.h"

namespace Voxy
{
    class LayerStack
    {
        using LayerVec = std::vector<Ref<Layer>>;

    public:
        LayerStack();
        ~LayerStack();

        void AddLayer(const Ref<Layer> &layer);
        void PushOverlay(const Ref<Layer> &overlay);
        void RemoveLayer(const Ref<Layer> &layer);
        void RemoveOverlay(const Ref<Layer> &overlay);

        inline LayerVec::iterator begin() { return m_Layers.begin(); }
        inline LayerVec::iterator end() { return m_Layers.end(); }

        inline LayerVec::reverse_iterator rbegin() { return m_Layers.rbegin(); }
        inline LayerVec::reverse_iterator rend() { return m_Layers.rend(); }

    private:
        LayerVec m_Layers;
        int m_LayerInsertIdx = 0;
    };
}