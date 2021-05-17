#include "window.h"
#include "../rendering/OpenGL_context.h"


Kranker3D::Window::Window(int _width, int _height, std::string& _title, GLFWmonitor* _monitor, GLFWwindow* _share): 
	width(_width), height(_height), title(_title), monitor(_monitor), share(_share), window(NULL)
{
	OpenGL_Context::getInstance(this);
	OpenGL_Context::getInstance(this)->init();

}

void Kranker3D::Window::run()
{

	OpenGL_Context::getInstance(this)->render();
}

bool Kranker3D::Window::isOpen()
{
	return OpenGL_Context::getInstance(this)->isOpen();
}		


//void Kranker3D::Window::terminate()
//{
//	spdlog::info("--- GLFW : Terminate window");
//	glfwTerminate();
//}
//
//void Kranker3D::Window::initContext()
//{
//	if (!glfwInit())
//	{
//		spdlog::error("--- GLFW : Failed to init GLFW");
//		exit(EXIT_FAILURE);
//	}
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	spdlog::info("--- GLFW : Initialize with OpenGL {}.{}", GLFW_CONTEXT_VERSION_MAJOR, GLFW_CONTEXT_VERSION_MINOR);
//
//}

//void Kranker3D::Window::initGlad()
//{
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		spdlog::error("--- GLAD : glad failed to initialize");
//		exit(EXIT_FAILURE);
//	}
//}



