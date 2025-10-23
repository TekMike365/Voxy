include("Dependencies.cmake")

add_library(Voxy STATIC
    "src/tmp.cpp"
)

target_link_libraries(Voxy PRIVATE
    OpenGL::GL
    glad
    # glfw
    # glm
    # imgui
    # spdlog
)

target_include_directories(Voxy PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

set_property(TARGET Voxy PROPERTY CXX_STANDARD 20)
set_property(TARGET Voxy PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET Voxy PROPERTY CXX_EXTENSIONS OFF)

# Compiler settings
if (MSVC)
    message(ERROR "Complier settings (MSVC): Why do you use this crap???")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -pedantic")
endif()
