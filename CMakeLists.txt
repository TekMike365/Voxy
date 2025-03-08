cmake_minimum_required(VERSION 3.22)
project(Voxy)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

include(cmake/CPM.cmake)

CPMAddPackage("gh:gabime/spdlog@1.15.1")

add_subdirectory(Voxy)
