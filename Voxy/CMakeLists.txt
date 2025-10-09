add_executable(Voxy
    "src/Log.cpp"
    "src/main.cpp"
    "src/Setup.cpp"
    "src/Application.cpp"

    "src/platform/GLFW/GLFW.cpp"
    "src/platform/GLFW/GLFW_Window.cpp"

    "src/platform/OpenGL/OpenGL_Renderer.cpp"
    "src/platform/OpenGL/OpenGL_GraphicsContext.cpp"

    "src/Layers/LayerStack.cpp"
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
    add_compile_options(-Werror -Wall -Wextra -Wpedantic)
endif()
