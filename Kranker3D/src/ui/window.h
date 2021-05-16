#pragma once
#include "../stdafx.h"

namespace Kranker3D {

	class Window {
	public:
		Window(int width, int height, const std::string& title = "Title", GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);
		void run();
		bool isOpen();
		void terminate();
		inline void setCursorPosCallback(GLFWcursorposfun  cursor_position_callback) { glfwSetCursorPosCallback(_window, cursor_position_callback); }
		inline void setMouseScrollCallback(GLFWscrollfun  scroll_callback) { glfwSetScrollCallback(_window, scroll_callback); }
		inline void setBackgroundColor(float r, float g, float b) { glClearColor(r, g, b, 1.0f); }
	//	float getElapsedTimeSeconde();
	//	void setBackgroundColor(GLfloat color[4]);

		//void setVSync();
		//void setFullscreen();
	private:
		GLFWwindow* _window;
		bool _fullscreen;
		bool _vsync;
		//Clock _clock;

		void initContext();
		void initGlad();

	};
}
