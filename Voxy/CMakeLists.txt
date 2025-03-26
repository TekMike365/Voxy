add_library(Voxy SHARED
    Log.cpp

    Voxy/Application.cpp
    Voxy/Voxy.cpp

    Voxy/Platform/Window/Window.cpp
    Voxy/Platform/Window/GLFW/GLFWWindow.cpp

    Voxy/Layers/LayerStack.cpp
    Voxy/Layers/ImGuiLayer.cpp
    Voxy/Layers/RenderingLayer.cpp

    ${IMGUI_SOURCE}
)

target_link_libraries(Voxy PRIVATE spdlog glfw OpenGL::GL glad)

target_include_directories(Voxy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${IMGUI_INCLUDE})


if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    add_compile_options(-Wall -Wextra)
endif()

