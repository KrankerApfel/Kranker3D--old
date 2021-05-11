#pragma once
#include "../../../stdafx.h"
#include "../../glm/glm/gtc/matrix_transform.hpp"
#include "../../glm/glm/gtx/quaternion.hpp"
namespace Kranker3D
{
	class Transform {
	private:
		glm::vec3 _localPosition;
		glm::vec3 _localScale;
		glm::quat _localRotation;
		glm::mat4 _model;

	public:
		void translate(glm::vec3 translate);
		void scale(glm::vec3 scale) ;
		void rotate(float degree, glm::vec3 rotate) ;
		inline glm::mat4 getModelMatrix() { return _model; };
		inline glm::vec3 getLocalPosition() {return _localPosition;}
		inline glm::vec3 getLocalScale() {return _localScale;}
		inline glm::quat getLocalRotation() {return _localRotation;}

	};
}