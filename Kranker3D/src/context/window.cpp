#include "window.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "OpenGL_context.h"
#include "ImGUI_context.h"
#include <algorithm>

Kranker3D::Window::Window(int _width, int _height, std::string& _title, std::shared_ptr<GLFWmonitor> _monitor, std::shared_ptr<GLFWwindow> _share):
	width(_width), height(_height), title(_title), monitor(_monitor), share(_share), window(NULL)
{}

void Kranker3D::Window::init()
{
	OpenGL_Context::getInstance(shared_from_this());
	OpenGL_Context::getInstance(shared_from_this()).init();
	ImGUI_Context::getInstance(shared_from_this());
	ImGUI_Context::getInstance(shared_from_this()).init();
}

void Kranker3D::Window::run()  
{
	OpenGL_Context::getInstance(shared_from_this()).preRender();
	ImGUI_Context::getInstance(shared_from_this()).preRender();
	
	OpenGL_Context::getInstance(shared_from_this()).render();

	std::for_each(_panels.begin(), _panels.end(), [](std::shared_ptr<Panel> p) {p->render(); });

	ImGUI_Context::getInstance(shared_from_this()).render();

	ImGUI_Context::getInstance(shared_from_this()).postRender();
	OpenGL_Context::getInstance(shared_from_this()).postRender();
}

bool Kranker3D::Window::isOpen()
{
	return OpenGL_Context::getInstance(shared_from_this()).isOpen();
}		
void  Kranker3D::Window::terminate() {
	ImGUI_Context::getInstance(shared_from_this()).terminate();
	OpenGL_Context::getInstance(shared_from_this()).terminate();
}