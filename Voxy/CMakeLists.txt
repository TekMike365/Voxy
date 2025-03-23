add_executable(
    Voxy main.cpp Log.cpp Application.cpp Voxy.cpp
    Platform/GLFW/GLFWWindow.cpp
    ${IMGUI_SOURCE}
)

target_link_libraries(Voxy PRIVATE spdlog glfw OpenGL::GL glad)

target_include_directories(Voxy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${IMGUI_INCLUDE})


if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    add_compile_options(-Wall -Wextra)
endif()

