cmake_minimum_required(VERSION 3.16)
project(test)
set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

# add_subdirectory("glfw-3.4")
add_subdirectory("imgui")
add_executable(test
		src/main.cpp
		include/glad/glad.h
		src/glad.c
		include/KHR/khrplatform.h
		)
target_include_directories(test PUBLIC include)
target_link_libraries(test glfw)
target_link_libraries(test imgui)

# find_package(OpenGL REQUIRED)
# find_package(glfw3 REQUIRED)
