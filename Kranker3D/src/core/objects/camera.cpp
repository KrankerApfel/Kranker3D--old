#include "Camera.h"
#include "../../stdafx.h"
#define DETLA_TIME 0.0016


Kranker3D::Camera::Camera(float width, float height, ProjectionType _projectionType)
{

	Near = .3f;
	Far = 1000;
	FoV = 60;

	projectionType = _projectionType;

	_height = height;
	_width = width;

	_transform->translate(glm::vec3(0, 0, -10));

}

glm::mat4 Kranker3D::Camera::getView() const { return _transform->getMatrix(); }
glm::mat4 Kranker3D::Camera::getProj() const {
	return  projectionType == Kranker3D::ProjectionType::PERSPECTIVE ?
		glm::perspective(glm::radians(FoV), _width / _height, Near, Far) :
		glm::ortho(glm::radians(FoV), _width / _height, Near, Far);
}

float Kranker3D::Camera::getAspectRatio()
{
	return _width / _height;
}

