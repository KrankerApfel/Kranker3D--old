#include "OpenGL_context.h"
#include "../stdafx.h"
#include "OpenGL_context.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

static Kranker3D::OpenGL_Context::* Kranker3D::OpenGL_Context::getInstance(Window* const window)
{
	std::lock_guard<std::mutex> lock(_mutex);
	if (_instance == nullptr)
	{
		_instance = new OpenGL_Context(window);
	}
	return _instance;
};


bool Kranker3D::OpenGL_Context::isOpen()
{
	return !glfwWindowShouldClose(_window->window);
}

void Kranker3D::OpenGL_Context::init()
{
	// 1. Init GLFW
	{
		if (!glfwInit())
		{
			spdlog::error("--- GLFW : Failed to init GLFW");
			exit(EXIT_FAILURE);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		spdlog::info("--- GLFW : Initialize with OpenGL {}.{}", GLFW_CONTEXT_VERSION_MAJOR, GLFW_CONTEXT_VERSION_MINOR);
	}

	// 2. Attach openGL context to GLFW window
	{
		_window->window = glfwCreateWindow(_window->width, _window->height, _window->title.c_str(), _window->monitor, _window->share);
		if (!_window->window) {
			spdlog::error("--- GLFW : Window creation failed.");
			glfwTerminate();
			exit(EXIT_FAILURE);
		}		glfwMakeContextCurrent(_window->window);
	}

	// .3 Init Glad
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			spdlog::error("--- GLAD : glad failed to initialize");
			exit(EXIT_FAILURE);
		}
	}

	//.4 Init callbacks and set options
	{
		glViewport(0, 0, _window->width, _window->height);
		glfwSetFramebufferSizeCallback(_window->window, framebuffer_size_callback);
		glEnable(GL_DEPTH_TEST);
		glfwSetInputMode(_window->window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
	}
	
}

void Kranker3D::OpenGL_Context::preRender()
{

}

void Kranker3D::OpenGL_Context::render()
{
	glfwSwapBuffers(_window->window);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Kranker3D::OpenGL_Context::postRender()
{
}

void Kranker3D::OpenGL_Context::terminate()
{
	spdlog::info("--- GLFW : Terminate window");
	glfwTerminate();
}

