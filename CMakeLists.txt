cmake_minimum_required(VERSION 3.16)
project(test)
set(CMAKE_CXX_STANDARD 17)

if (WIN32)
	list(APPEND CMAKE_PREFIX_PATH "C:/Program Files (x86)/GLFW/lib/cmake")
endif()

find_package(glfw3 REQUIRED)
add_subdirectory("glm")
add_subdirectory("imgui")

add_executable(test
		"src/main.cpp"
		"include/glad/glad.h"
		"src/glad.c"
		"include/KHR/khrplatform.h"
		"include/app.h" "include/window.h" "src/app.cpp" "src/window.cpp")
target_include_directories(test PUBLIC include)
target_link_libraries(test glfw)
target_link_libraries(test glm::glm)
target_link_libraries(test imgui)
