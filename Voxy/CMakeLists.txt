add_executable(Voxy main.cpp Log.cpp Application.cpp Voxy.cpp)

target_link_libraries(Voxy PRIVATE spdlog glfw)
