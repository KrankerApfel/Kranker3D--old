#pragma once
#include "../../stdafx.h"

namespace Kranker3D {

	class Window {
	public:
		Window(int width, int height, const std::string& title = "Title", GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);
		void run();
		bool isOpen();
		void terminate();
	//	float getElapsedTimeSeconde();
	//	void setBackgroundColor(GLfloat color[4]);
	//	sf::Event getInputEvent() { return _inputEvent; }

		//void setVSync();
		//void setFullscreen();
	private:
		GLFWwindow* _window;
		bool _fullscreen;
		bool _vsync;
		//Clock _clock;
		//Event _inputEvent;

		void initContext();
		void initGlad();

	};
}
