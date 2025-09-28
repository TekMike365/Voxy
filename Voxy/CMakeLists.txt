# Compiler settings
if (MSVC)
    message(WARNING "Complier settings (MSVC): Why do you use this crap???")
else()
    add_compile_options(-Werror -Wall -Wextra -Wpedantic)
endif()

add_executable(Voxy
    "src/Log.cpp"
    "src/main.cpp"
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
