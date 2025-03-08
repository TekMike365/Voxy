add_executable(Voxy main.cpp Log.cpp Application.cpp)

target_link_libraries(Voxy PRIVATE spdlog glfw)
