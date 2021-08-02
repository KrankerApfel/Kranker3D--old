#pragma once
#include <glm/gtx/transform.hpp>
#include <memory>
#include "panel.h"
#include "../core/objects/object.h"
namespace Kranker3D {
	class PropertyPanel : public Panel
	{
	private:
		std::shared_ptr<Object> _obj;

	public:

		PropertyPanel();
		PropertyPanel(std::string _title);

		void linkObject(std::shared_ptr<Object> const obj);
		void render() override;

	};

}