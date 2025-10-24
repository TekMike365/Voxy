project(Voxy)
include("Dependencies.cmake")

add_library(${PROJECT_NAME} STATIC
    "src/Test.cpp"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    spdlog
    glfw
    OpenGL::GL
    glad
    glm
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)

include("${CMAKE_SOURCE_DIR}/CompilerSettings.cmake")
