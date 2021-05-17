#pragma once
#include "../stdafx.h"

namespace Kranker3D {

	class Window {
	public:
		Window(int width, int height, std::string& title, GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);
		void run();
		bool isOpen();
		void terminate();
		inline void setCursorPosCallback(GLFWcursorposfun  cursor_position_callback) { glfwSetCursorPosCallback(window, cursor_position_callback); }
		inline void setMouseScrollCallback(GLFWscrollfun  scroll_callback) { glfwSetScrollCallback(window, scroll_callback); }
		inline void setBackgroundColor(float r, float g, float b) { glClearColor(r, g, b, 1.0f); }
		GLFWwindow* window;
		int width, height;
		std::string& title;
		GLFWmonitor* monitor;
		GLFWwindow* share;
	

	/*private:
		bool _fullscreen;
		bool _vsync;

		void initContext();
		void initGlad();*/

	};
}
