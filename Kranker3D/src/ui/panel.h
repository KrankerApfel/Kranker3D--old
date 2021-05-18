#pragma
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Kranker3D {
	class Panel {
	public:
		Panel() {};
		void render() {

			ImGui::Begin("Properties");

			ImGui::Text("Transform");
			ImGui::PushItemWidth(150.f);
			ImGui::Text("Youpi");
			ImGui::Text("Oui");
			ImGui::Text("So vaporwaaaave");


			ImGui::End();
		};
	};

}