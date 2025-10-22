#include "Entity.hpp"

#include "Log.hpp"

#include "Transform.hpp"

namespace Voxy {

void Entity::Destroy() {
    auto registry = LockRegistry();
    registry->destroy(m_ID);
    m_ID = entt::null;
}

Ref<entt::registry> Entity::LockRegistry() {
    if (!m_Registry.expired()) {
        VoxyCoreWarn("ECS: Tried to destroy entity in a non-existing scene.");
        return nullptr;
    }

    auto registry = m_Registry.lock();

    if (!registry->valid(m_ID)) {
        VoxyCoreWarn("ECS: Tried to destroy a non-existing entity.");
        return nullptr;
    }

    return registry;
}

} // namespace Voxy
