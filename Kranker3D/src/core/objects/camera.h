#pragma once
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include "../../core/objects/transform.h"

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

	class Camera {

	private:

		Transform _transform;
		float _width, _height;

	public:
		// lens settings
		float Near, Far, FoV;
		ProjectionType projectionType;

		Camera(float width, float height, ProjectionType projectionType = ProjectionType::PERSPECTIVE);

		//getter
		inline glm::mat4 getView() const { return _transform.getMatrix(); }
		inline glm::mat4 getProj() const {
			return  projectionType == Kranker3D::ProjectionType::PERSPECTIVE ?
				glm::perspective(glm::radians(FoV), _width / _height, Near, Far) :
				glm::ortho(glm::radians(FoV), _width / _height, Near, Far);
		}
		inline Transform* getTransform() { return &_transform; }
		inline float getAspectRatio() { return _width/_height; }

	};
}