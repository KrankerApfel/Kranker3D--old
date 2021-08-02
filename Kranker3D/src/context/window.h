#pragma once
#include <memory>
#include <vector>
#include "../stdafx.h"
#include "../ui/panel.h"
#include "customSmartPointers.h"

namespace Kranker3D {

	class Window : public std::enable_shared_from_this<Window> {
	private:
		std::vector<std::shared_ptr<Panel>> _panels;
	public:
		Window(int width, int height, std::string& title, std::shared_ptr<GLFWmonitor> monitor = NULL, std::shared_ptr<GLFWwindow> share = NULL);
		void init();
		void run();
		bool isOpen();
		void terminate();
		inline void setCursorPosCallback(GLFWcursorposfun  cursor_position_callback) { glfwSetCursorPosCallback(window.get(), cursor_position_callback); }
		inline void setMouseScrollCallback(GLFWscrollfun  scroll_callback) { glfwSetScrollCallback(window.get(), scroll_callback); }
		inline void setBackgroundColor(float r, float g, float b) { glClearColor(r, g, b, 1.0f); }
		inline void linkPanel(std::shared_ptr<Panel> const panel) { _panels.push_back(panel); }
		unique_GLFWwindow_ptr window;
		int width, height;
		std::string& title;
		std::shared_ptr<GLFWmonitor> monitor;
		std::shared_ptr<GLFWwindow> share;

	};


}
