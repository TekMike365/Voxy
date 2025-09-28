cmake_minimum_required(VERSION 3.22)
project(Voxy)

# Adding dependencies
include(cmake/CPM.cmake)

CPMAddPackage("gh:gabime/spdlog@1.15.1")
CPMAddPackage("gh:glfw/glfw#3.4")
CPMAddPackage("gh:g-truc/glm#1.0.1")

find_package(OpenGL)
if(NOT OPENGL_FOUND)
    message(SEND_ERROR "OpenGL required but not found.")
endif()

add_subdirectory(vendor/glad)

# ImGui
set(IMGUI_PATH "${PROJECT_SOURCE_DIR}/vendor/imgui")
add_library(imgui STATIC
    "${IMGUI_PATH}/imgui.cpp"
    "${IMGUI_PATH}/imgui_demo.cpp"
    "${IMGUI_PATH}/imgui_draw.cpp"
    "${IMGUI_PATH}/imgui_tables.cpp"
    "${IMGUI_PATH}/imgui_widgets.cpp"

    "${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp"
    "${IMGUI_PATH}/backends/imgui_impl_glfw.cpp"

    "${IMGUI_PATH}/misc/cpp/imgui_stdlib.cpp"
)
target_link_libraries(imgui PRIVATE
    glfw
)
target_include_directories(imgui PUBLIC 
    ${IMGUI_PATH}
    "${IMGUI_PATH}/backends"
    "${IMGUI_PATH}/misc/cpp"
)

# entt
set(ENTT_INCLUDE "${PROJECT_SOURCE_DIR}/vendor/entt")

# Adding projects
add_subdirectory(Voxy)
