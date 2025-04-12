#include "Scene.h"

#include "Components/Camera.h"

#include "Voxy/Renderer/Renderer.h"

namespace Voxy
{
    Scene::Scene()
    {
        m_Registry = std::make_shared<entt::registry>();
    }

    void Scene::Update(TimeStep dt)
    {
        // TODO: ! make it data oriented !

        // TODO: Make the Renderer have a command buffer ?
        // TODO: Make Systems that act on data
        // TODO: The renderer systems are responsable for batching and caching and then submiting the data for rendering

        bool began = false;
        for (auto [ett, camera] : m_Registry->view<Camera>().each())
        {
            if (!camera.IsMain())
                continue;
            // Camera is Main
            Entity entity(ett, m_Registry);
            Transform defaultTransform;
            Renderer::Begin(&camera, &(entity.HasComponent<Transform>() ? entity.GetComponent<Transform>() : defaultTransform));
            began = true;
        }

        if (began)
            Renderer::End();
    }
}