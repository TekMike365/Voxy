project(Voxy)
include("Dependencies.cmake")

add_definitions(-DVOXY_CORE)

add_library(${PROJECT_NAME} STATIC
    "src/Test.cpp"
    "src/Log.cpp"
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    OpenGL::GL
    glad
    glm

    PUBLIC
    spdlog
)

include("${CMAKE_SOURCE_DIR}/CompilerSettings.cmake")
