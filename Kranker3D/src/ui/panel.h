#pragma once
#include <string>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Kranker3D {
	class Panel {
	public:
		const std::string title;
		Panel(std::string);
		virtual void render() = 0;
	};


}