cmake_minimum_required(VERSION 3.22)
project(Voxy)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

include(cmake/CPM.cmake)

CPMAddPackage("gh:gabime/spdlog@1.15.1")
CPMAddPackage("gh:glfw/glfw#3.4")

find_package(OpenGL)
if(NOT OPENGL_FOUND)
    message(SEND_ERROR "OpenGL required but not found.")
endif()

add_subdirectory(vendor/glad)

add_subdirectory(Voxy)
