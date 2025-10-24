add_subdirectory("vendor/spdlog")
add_subdirectory("vendor/glfw")
add_subdirectory("vendor/glad")
add_subdirectory("vendor/glm")

find_package(OpenGL)
if(NOT OPENGL_FOUND)
    message(SEND_ERROR "OpenGL required but not found.")
endif()

#
# Dear ImGui
#

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
target_link_libraries(imgui PRIVATE glfw)
target_include_directories(imgui PUBLIC
    ${IMGUI_PATH}
    "${IMGUI_PATH}/backends"
)
set(IMGUI_PATH)
