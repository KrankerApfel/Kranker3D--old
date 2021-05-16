#include "Camera.h"
#include "../../stdafx.h"
#define DETLA_TIME 0.0016


Kranker3D::Camera::Camera(float width, float height, ProjectionType _projectionType  )
{

	Near = .3f;
	Far = 1000;
	FoV = 60;

	projectionType = _projectionType;

	_height =  height;
	_width = width;

	_transform.translate(glm::vec3(0, 0, -10));

}


