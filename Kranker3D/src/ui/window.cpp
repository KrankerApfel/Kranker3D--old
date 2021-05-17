#include "window.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "../rendering/OpenGL_context.h"
#include "../rendering/ImGUI_context.h"


Kranker3D::Window::Window(int _width, int _height, std::string& _title, GLFWmonitor* _monitor, GLFWwindow* _share): 
	width(_width), height(_height), title(_title), monitor(_monitor), share(_share), window(NULL)
{
	OpenGL_Context::getInstance(this);
	OpenGL_Context::getInstance(this)->init();
	ImGUI_Context::getInstance(this);
	ImGUI_Context::getInstance(this)->init();

}

void Kranker3D::Window::run() //void(*render_callback)()
{
	OpenGL_Context::getInstance(this)->preRender();
	ImGUI_Context::getInstance(this)->preRender();

	//render_callback();
	{

		ImGui::Begin("Properties");

		ImGui::Text("Transform");
		ImGui::PushItemWidth(150.f);
		ImGui::Text("Youpi");
		ImGui::Text("Oui");
		ImGui::Text("So vaporwaaaave");


		ImGui::End();
	}


	OpenGL_Context::getInstance(this)->render();
	ImGUI_Context::getInstance(this)->render();

	ImGUI_Context::getInstance(this)->postRender();
	OpenGL_Context::getInstance(this)->postRender();
}

bool Kranker3D::Window::isOpen()
{
	return OpenGL_Context::getInstance(this)->isOpen();
}		
