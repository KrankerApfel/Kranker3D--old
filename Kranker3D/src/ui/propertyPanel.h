#pragma once
#include <glm/gtx/transform.hpp>
#include "panel.h"
#include "../core/objects/object.h"
namespace Kranker3D {
	class PropertyPanel : public Panel
	{
	private:
		Object* _obj;

	public:

		PropertyPanel() { title = "Property"; _obj = nullptr; };

		void linkObject(Object* const obj) { _obj = obj; }
		void render() override {


			ImGui::Begin(title);

			if (ImGui::CollapsingHeader("Transform"))
			{


				ImGui::PushItemWidth(50.0f);

				ImGui::Text("Position");

				
				ImGui::DragFloat("##PositionX", &_obj->getTransform()->position.x, 0.1f, 0.0f, 0.0f, "%.2f");
				ImGui::SameLine(); ImGui::DragFloat("##PositionY", &_obj->getTransform()->position.y, 0.1f, 0.0f, 0.0f, "%.2f");
				ImGui::SameLine(); ImGui::DragFloat("##PositionZ", &_obj->getTransform()->position.z, 0.1f, 0.0f, 0.0f, "%.2f");

				ImGui::Text("Rotation"); // TODO : glm::rotate

				ImGui::DragFloat("##RotationX", &_obj->getTransform()->rotation.x, 0.1f, 0.0f, 0.0f, "%.2f");
				ImGui::SameLine(); ImGui::DragFloat("##RotationY", &_obj->getTransform()->rotation.y, 0.1f, 0.0f, 0.0f, "%.2f");
				ImGui::SameLine(); ImGui::DragFloat("##RotationZ", &_obj->getTransform()->rotation.z, 0.1f, 0.0f, 0.0f, "%.2f");
				

				ImGui::Text("Scale");

				ImGui::DragFloat("##ScaleX", &_obj->getTransform()->scale.x, 0.1f, 0.0f, 0.0f, "%.2f");
				ImGui::SameLine(); ImGui::DragFloat("##ScaleY", &_obj->getTransform()->scale.y, 0.1f, 0.0f, 0.0f, "%.2f");
				ImGui::SameLine(); ImGui::DragFloat("##ScaleZ", &_obj->getTransform()->scale.z, 0.1f, 0.0f, 0.0f, "%.2f");


			}

			if (ImGui::CollapsingHeader("Material"))
			{
				const char* items[] = { "Phong", "Lambert", "Unlit" };
				static const char* current_item = items[0];

				if (ImGui::BeginCombo("##select material", current_item)) 
				{
					for (int n = 0; n < IM_ARRAYSIZE(items); n++)
					{
						bool is_selected = (current_item == items[n]);
						if (ImGui::Selectable(items[n], is_selected)) {
							current_item = items[n];
							if (is_selected)
								ImGui::SetItemDefaultFocus();  

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



	};

}