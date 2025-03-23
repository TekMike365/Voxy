cmake_minimum_required(VERSION 3.22)
project(Voxy)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)


# Adding dependencies
include(cmake/CPM.cmake)

CPMAddPackage("gh:gabime/spdlog@1.15.1")
CPMAddPackage("gh:glfw/glfw#3.4")

find_package(OpenGL)
if(NOT OPENGL_FOUND)
    message(SEND_ERROR "OpenGL required but not found.")
endif()

add_subdirectory(vendor/glad)

set(IMGUI_PATH "${PROJECT_SOURCE_DIR}/vendor/imgui")
set(IMGUI_SOURCE
    "${IMGUI_PATH}/imgui.cpp"
    "${IMGUI_PATH}/imgui_demo.cpp"
    "${IMGUI_PATH}/imgui_draw.cpp"
    "${IMGUI_PATH}/imgui_tables.cpp"
    "${IMGUI_PATH}/imgui_widgets.cpp"

    "${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp"
    "${IMGUI_PATH}/backends/imgui_impl_glfw.cpp"
)
set(IMGUI_INCLUDE ${IMGUI_PATH} "${IMGUI_PATH}/backends")

# Adding projects
add_subdirectory(Voxy)
