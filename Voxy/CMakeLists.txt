add_executable(Voxy
    "src/Log.cpp"
    "src/main.cpp"
    "src/Setup.cpp"
    "src/Core/Application.cpp"

    "src/Platform/GLFW/GLFW.cpp"
    "src/Platform/GLFW/Window.cpp"

    "src/Platform/OpenGL/OpenGL.cpp"
    "src/Platform/OpenGL/GraphicsContext.cpp"

    "src/Platform/OpenGL/Renderer/Renderer.cpp"
    "src/Platform/OpenGL/Renderer/Buffer.cpp"
    "src/Platform/OpenGL/Renderer/Mesh.cpp"
    "src/Platform/OpenGL/Renderer/Shader.cpp"

    "src/Layers/LayerStack.cpp"
    "src/Layers/TestLayer.cpp"
)
target_link_libraries(Voxy PRIVATE
    spdlog
    glfw
    OpenGL::GL
    glad
    glm
    imgui
)
target_include_directories(Voxy PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    ${ENTT_INCLUDE}
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
