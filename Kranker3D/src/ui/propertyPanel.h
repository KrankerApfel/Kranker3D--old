#pragma once
#include "panel.h"

namespace Kranker3D {
	class PropertyPanel : public Panel
	{
	public:

		PropertyPanel() { title = "Property"; };

		void render() override {

			ImGui::Begin(title);

			if (ImGui::CollapsingHeader("Transform"))
			{
				float pos[3] = { 10,15,20 };
				ImGui::PushItemWidth(150.f);

				ImGui::InputFloat3("Position", pos); // TODO : link to object transform

				ImGui::InputFloat3("Rotation", pos); // TODO : link to object transform

				ImGui::InputFloat3("Scale", pos); // TODO : link to object transform

			}

			if (ImGui::CollapsingHeader("Material"))
			{
				const char* items[] = { "Phong", "Lambert", "Unlit" };
				static const char* current_item = items[0];

				if (ImGui::BeginCombo("##select material", current_item)) // The second parameter is the label previewed before opening the combo.
				{
					for (int n = 0; n < IM_ARRAYSIZE(items); n++)
					{
						bool is_selected = (current_item == items[n]); // You can store your selection however you want, outside or inside your objects
						if (ImGui::Selectable(items[n], is_selected)) {
							current_item = items[n];
							if (is_selected)
								ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)7

						}

					}
					ImGui::EndCombo();
				}


				float col[4] = { 0.5,0.15,0.28 };
				ImGui::PushItemWidth(150.f);

				ImGui::ColorEdit4("Diffuse color", col); // TODO : link to object material
				float v;
				ImGui::SliderFloat("Roughness", &v, 0.0f, 1.0f); // TODO : link to object material
				ImGui::SliderFloat("Metallic", &v, 0.0f, 1.0f); // TODO : link to object material
				ImGui::Text("Here image picker for texture");

			}

			ImGui::End();
		};

	private:

	};
	
}