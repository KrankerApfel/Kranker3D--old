#pragma once
#include "../../stdafx.h"
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
namespace Kranker3D
{
	class Transform {
		

	public:

		glm::vec3 position;
		glm::vec3 scale;
		glm::quat rotation;

		Transform();
		
		glm::vec3 getForward() const;
		inline glm::vec3 getRight() const { return glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), getForward()); }
		inline glm::vec3 getUp() const { return glm::cross(getForward(), getRight()); };

		inline glm::mat4 getMatrix() const
		{
			return glm::scale(glm::translate(position) * glm::toMat4(rotation), scale);
		};

		void translate(glm::vec3 translate);
		void rescale(float scale_factor);
		void rotate(float degree, glm::vec3 rotate);
		inline void lookAt(glm::vec3 direction) { rotation = glm::quat(glm::lookAt(position, direction, getUp())); };
		void lerp(glm::vec3 origine, glm::vec3 goal, float step);

	};
}