#include <memory>
#include "OpenGL_context.h"
#include "../stdafx.h"




Kranker3D::OpenGL_Context::OpenGL_Context(std::shared_ptr<Kranker3D::Window> window) : _window(window) {}

Kranker3D::OpenGL_Context& Kranker3D::OpenGL_Context::getInstance(std::shared_ptr<Window> window) {
	static std::unique_ptr<OpenGL_Context> instance(new OpenGL_Context(window));
	return *instance;
};

bool Kranker3D::OpenGL_Context::isOpen()
{
	return !glfwWindowShouldClose(_window->window.get());
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
		_window->window = unique_GLFWwindow_ptr(glfwCreateWindow(_window->width, _window->height, _window->title.c_str(), _window->monitor.get(), _window->share.get()));
		if (!_window->window) {
			spdlog::error("--- GLFW : Window creation failed.");
			glfwTerminate();
			exit(EXIT_FAILURE);
		}		glfwMakeContextCurrent(_window->window.get());
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
		glfwSetFramebufferSizeCallback(_window->window.get(), [](GLFWwindow* window, int w, int h) {glViewport(0, 0, w, h); });
		glEnable(GL_DEPTH_TEST);
		glfwSetInputMode(_window->window.get(), GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
	}

}

void Kranker3D::OpenGL_Context::preRender()
{
	glfwPollEvents();
}

void Kranker3D::OpenGL_Context::render()
{
	glfwSwapBuffers(_window->window.get());
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

