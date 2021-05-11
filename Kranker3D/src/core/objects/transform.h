#pragma once
#include "../../../stdafx.h"
#include "../../glm/glm/gtx/transform.hpp"
#include "../../glm/glm/gtx/quaternion.hpp"
namespace Kranker3D
{
	class Transform {
	private:
		glm::vec3 _position;
		glm::vec3 _scale;
		glm::quat _rotation;

	public:
		Transform();
		inline glm::vec3 getPosition() const { return _position; };
		inline glm::vec3 getScale()  const { return _scale; };
		inline glm::quat getRotation()  const { return _rotation; };

		inline glm::mat4 getMatrix() const
		{
			return glm::scale(glm::translate(_position)* glm::toMat4(_rotation),_scale);
 		};

		void translate(glm::vec3 translate);
		void scale(glm::vec3 scale);
		void rotate(float degree, glm::vec3 rotate);

	};
}