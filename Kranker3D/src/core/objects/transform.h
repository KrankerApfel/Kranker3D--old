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
		glm::vec3 getPosition() const { return _position; };
		glm::vec3 getScale()  const { return _scale; };
		glm::quat getRotation()  const { return _rotation; };

		glm::mat4 getMatrix() const
		{
			glm::mat4 translation = glm::translate( _position);
			glm::mat4 rotation = glm::toMat4(_rotation);
			glm::mat4 scale = glm::scale(_scale);
			return translation * rotation * scale;
		};

		void translate(glm::vec3 translate);
		void scale(glm::vec3 scale);
		void rotate(float degree, glm::vec3 rotate);

	};
}