#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main() { 
	if (!glfwInit()) {
		std::cerr << "GLFW FAILED TO INIT\n";
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	auto *window = glfwCreateWindow(640, 480, "Test", NULL, NULL);
	if (!window) {
		std::cerr << "WINDOW FAILED TO CREATE\n";
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window)) {
		glViewport(0, 0, 640, 480);
		glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);	
	glfwTerminate();
}
