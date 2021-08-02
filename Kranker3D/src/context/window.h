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
		void setCursorPosCallback(GLFWcursorposfun  cursor_position_callback);
		void setMouseScrollCallback(GLFWscrollfun  scroll_callback);
		void setBackgroundColor(float r, float g, float b);
		void linkPanel(std::shared_ptr<Panel> const panel);
		unique_GLFWwindow_ptr window;
		int width, height;
		std::string& title;
		std::shared_ptr<GLFWmonitor> monitor;
		std::shared_ptr<GLFWwindow> share;

	};


}
