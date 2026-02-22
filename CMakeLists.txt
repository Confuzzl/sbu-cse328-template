cmake_minimum_required(VERSION 3.16)
project(test)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)


add_executable(test
		"src/main.cpp"
		"src/app.cpp"
		"src/util.cpp" 
		"src/gl/uniform.cpp" 
		"src/gl/gl_object.cpp" 
		"src/gl/glsl_object.cpp"  
		"include/stb_image.h"
		"include/app.h"
		 
		"include/color.h" 
		"include/gl/gl_object.h" 
		"include/gl/glsl_object.h" 
		"include/gl/uniform.h" 
		"include/gl/vao.h" 
		"include/gl/vertex_layout.h" 
		"include/gl/component/vertex.h" 
		"include/gl/component/fragment.h" "include/gl/texture.h" "src/gl/texture.cpp" "include/renderer.h" "src/color.cpp" "src/gl/vertex_layout.cpp" "src/renderer.cpp" "include/callback.h" "src/callback.cpp" "include/input/key.h" "include/input/input_handler.h" "src/input/key.cpp" "src/input/input_handler.cpp" "include/scene.h" "src/scene.cpp")
target_include_directories(test PUBLIC include)
target_compile_definitions(test PRIVATE SOURCE_DIR="${CMAKE_SOURCE_DIR}")

if (WIN32)
	list(APPEND CMAKE_PREFIX_PATH "C:/Program Files (x86)/GLFW/lib/cmake")
endif()
find_package(glfw3 REQUIRED)
target_link_libraries(test glfw)

add_subdirectory("glad")
target_link_libraries(test glad)

add_subdirectory("glm")
target_link_libraries(test glm::glm)

add_subdirectory("imgui")
target_link_libraries(test imgui)

add_subdirectory("fmt")
target_link_libraries(test fmt::fmt)
