project(Sandbox)

add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} PRIVATE Voxy)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${PROJECT_SOURCE_DIR}/src"
)

include("${CMAKE_SOURCE_DIR}/CompilerSettings.cmake")
