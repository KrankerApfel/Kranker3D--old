#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include "../../core/objects/object.h"

// TODO : 
// --------- LookAt
// --------- screenToWorldPoint
// --------- screenToViewportPoint
// --------- screenPointToRay
// --------- viewportToWorldPoint
// --------- viewportToScreenPoint
// --------- viewportPointToRay
// --------- worldToScreenPoint
// --------- worldToViewportPoint


namespace Kranker3D
{

	enum class ProjectionType { PERSPECTIVE = 0, ORTHOGONAL = 1 };

	class Camera : public Object {

	private:

		float _width, _height;

	public:
		// lens settings
		float Near, Far, FoV;
		ProjectionType projectionType;

		Camera(float width, float height, ProjectionType projectionType = ProjectionType::PERSPECTIVE);

		//getter
		glm::mat4 getView() const;
		glm::mat4 getProj() const;
		float getAspectRatio();

	};
}