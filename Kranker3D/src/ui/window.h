#pragma once
#include "../../stdafx.h"

namespace Kranker3D {

	class Window {
	public:
		Window(int width, int height, const std::string& title = "Title", GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);
		void run();
		bool isOpen();
		void terminate();
		inline bool getKeyPress(int keycode) { return glfwGetKey(_window, keycode) == GLFW_PRESS; }
		inline bool getKeyRelease(int keycode) { return glfwGetKey(_window, keycode) == GLFW_RELEASE; }
		inline bool getKeyDown(int keycode) { return glfwGetKey(_window, keycode) == GLFW_REPEAT; }
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
