#pragma once
#include "../stdafx.h"
#include "../ui/panel.h"
#include <vector>
namespace Kranker3D {

	class Window {
	private:
		std::vector<Panel*> _panels;
	public:
		Window(int width, int height, std::string& title, GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);
		void run(/*void (*render_callback)()*/);
		bool isOpen();
		void terminate();
		inline void setCursorPosCallback(GLFWcursorposfun  cursor_position_callback) { glfwSetCursorPosCallback(window, cursor_position_callback); }
		inline void setMouseScrollCallback(GLFWscrollfun  scroll_callback) { glfwSetScrollCallback(window, scroll_callback); }
		inline void setBackgroundColor(float r, float g, float b) { glClearColor(r, g, b, 1.0f); }
		inline void linkPanel(Panel* const panel) { _panels.push_back(panel); }
		GLFWwindow* window;
		int width, height;
		std::string& title;
		GLFWmonitor* monitor;
		GLFWwindow* share;

	};
}
