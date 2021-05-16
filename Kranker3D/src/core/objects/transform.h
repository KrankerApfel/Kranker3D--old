#pragma once
#include "../../stdafx.h"
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
		glm::vec3 getForward() const;
		inline glm::vec3 getRight() const { return glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), getForward()); }
		inline glm::vec3 getUp() const { return glm::cross(getForward(), getRight()); };

		inline glm::mat4 getMatrix() const
		{
			return glm::scale(glm::translate(_position) * glm::toMat4(_rotation), _scale);
		};

		void translate(glm::vec3 translate);
		void scale(glm::vec3 scale);
		void rotate(float degree, glm::vec3 rotate);
		inline void lookAt(glm::vec3 direction) { _rotation = glm::quat(glm::lookAt(_position,direction, getUp())); };
		void lerp(glm::vec3 origine, glm::vec3 goal, float step);

	};
}