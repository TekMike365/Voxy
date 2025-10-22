add_library(Voxy STATIC
    "src/Log.cpp"
    "src/Setup.cpp"
    "src/Core/Application.cpp"

    "src/Platform/GLFW/GLFW.cpp"
    "src/Platform/GLFW/Window.cpp"

    "src/Platform/OpenGL/OpenGL.cpp"
    "src/Platform/OpenGL/GraphicsContext.cpp"

    "src/Platform/OpenGL/Renderer/Renderer.cpp"
    "src/Platform/OpenGL/Renderer/Buffer.cpp"
    "src/Platform/OpenGL/Renderer/VertexArray.cpp"
    "src/Platform/OpenGL/Renderer/Shader.cpp"
    "src/Platform/OpenGL/Renderer/RenderCommands.cpp"
    "src/Platform/OpenGL/Renderer/CommandQueue.cpp"

    "src/Layers/LayerStack.cpp"

    "src/ECS/Scene.cpp"
    "src/ECS/Entity.cpp"
)
target_link_libraries(Voxy
    PRIVATE
    glfw
    OpenGL::GL
    glad

    PUBLIC
    glm
    imgui
    spdlog
)
target_include_directories(Voxy
    PRIVATE
    "${ENTT_INCLUDE}"

    PUBLIC # for now
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

set_property(TARGET Voxy PROPERTY CXX_STANDARD 20)
set_property(TARGET Voxy PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET Voxy PROPERTY CXX_EXTENSIONS OFF)

# Compiler settings
if (MSVC)
    message(ERROR "Complier settings (MSVC): Why do you use this crap???")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -pedantic")
endif()
