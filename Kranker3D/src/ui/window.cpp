#include "window.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
Kranker3D::Window::Window(int width, int height, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share)
{
	initContext();
	_window = glfwCreateWindow(width, height, title.c_str(), monitor, share);
	if (!_window) {
		spdlog::error("GLFW", "Window creation failed.");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	spdlog::info("GLFW", "Fullscreen : " + (monitor != NULL));
	glfwMakeContextCurrent(_window);
	initGlad();
	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);


}

void Kranker3D::Window::run()
{
	while (isOpen())
	{
		glfwSwapBuffers(_window);
		glfwPollEvents();
	}
}

bool Kranker3D::Window::isOpen()
{
	return !glfwWindowShouldClose(_window);
}

void Kranker3D::Window::terminate()
{
	spdlog::info("GLFW", "Terminate window");
	glfwTerminate();
}

void Kranker3D::Window::initContext()
{
	if (!glfwInit())
	{
		spdlog::error("GLFW", "Failed to init GLFW");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	spdlog::info("GLFW", "Initialize with OpenGL " + GLFW_CONTEXT_VERSION_MAJOR + '.' + GLFW_CONTEXT_VERSION_MINOR);

}

void Kranker3D::Window::initGlad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		spdlog::error("GLAD", "GLAD did not initialize");
		exit(EXIT_FAILURE);
	}
}



