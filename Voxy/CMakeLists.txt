add_executable(
    Voxy main.cpp Log.cpp Application.cpp Voxy.cpp
    Platform/GLFW/GLFWWindow.cpp
)

target_link_libraries(Voxy PRIVATE spdlog glfw)

target_include_directories(Voxy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    add_compile_options(-Wall -Wextra)
endif()

