add_library(Voxy SHARED
    Log.cpp

    Voxy/Application.cpp
    Voxy/Setup.cpp

    Voxy/Window.cpp
    Voxy/Graphics/GraphicsContext.cpp
    Voxy/Graphics/VertexBuffer.cpp

    Voxy/Platform/GLFW/Window.cpp
    Voxy/Platform/OpenGL/GraphicsContext.cpp
    Voxy/Platform/OpenGL/VertexBuffer.cpp

    Voxy/Layers/LayerStack.cpp
    Voxy/Layers/ImGuiLayer.cpp
    Voxy/Layers/RenderingLayer.cpp

    ${IMGUI_SOURCE}
)

target_link_libraries(Voxy PUBLIC spdlog glfw OpenGL::GL glad glm)

target_include_directories(Voxy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${IMGUI_INCLUDE})


if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    add_compile_options(-Wall -Wextra)
endif()

