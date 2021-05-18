#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Kranker3D {
	class Panel {
	public:
		const char* title;

		Panel() { title = "Panel title"; };
		virtual void render() {};

			
	};


}