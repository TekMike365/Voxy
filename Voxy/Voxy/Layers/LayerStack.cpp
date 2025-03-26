#include "LayerStack.h"

#include "Log.h"

namespace Voxy
{
    LayerStack::LayerStack()
    {
    }

    LayerStack::~LayerStack()
    {
        for (Ref<Layer> layer : m_Layers)
        {
            layer->OnDetach();
            VOXY_CORE_TRACE("Detaching layer: {}", layer->GetName());
        }
    }

    void LayerStack::AddLayer(const Ref<Layer> &layer)
    {
        m_Layers.insert(m_Layers.begin() + m_LayerInsertIdx++, layer);
        layer->OnAttach();
        VOXY_CORE_TRACE("Attaching layer: {}", layer->GetName());
    }

    void LayerStack::PushOverlay(const Ref<Layer> &overlay)
    {
        m_Layers.push_back(overlay);
        overlay->OnAttach();
        VOXY_CORE_TRACE("Attaching overlay: {}", overlay->GetName());
    }

    void LayerStack::RemoveLayer(const Ref<Layer> &layer)
    {
        auto end = m_Layers.begin() + m_LayerInsertIdx;
        auto it = std::find(m_Layers.begin(), end, layer);
        if (it != end)
        {
            m_Layers.erase(it);
            layer->OnDetach();
            VOXY_CORE_TRACE("Detaching layer: {}", layer->GetName());
        }
    }

    void LayerStack::RemoveOverlay(const Ref<Layer> &overlay)
    {
        auto it = std::find(m_Layers.begin() + m_LayerInsertIdx, m_Layers.end(), overlay);
        if (it != m_Layers.end())
        {
            m_Layers.erase(it);
            overlay->OnDetach();
            VOXY_CORE_TRACE("Detaching overlay: {}", overlay->GetName());
        }
    }
}