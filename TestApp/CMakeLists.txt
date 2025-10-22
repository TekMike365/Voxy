add_executable(TestApp
    "src/main.cpp"
    "src/TestLayer.cpp"
)
target_link_libraries(TestApp PRIVATE Voxy)
target_include_directories(TestApp PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src")

set_property(TARGET TestApp PROPERTY CXX_STANDARD 20)
set_property(TARGET TestApp PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET TestApp PROPERTY CXX_EXTENSIONS OFF)

# Compiler settings
if (MSVC)
    message(ERROR "Complier settings (MSVC): Why do you use this crap???")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -pedantic")
endif()
