#include "Camera.h"
#include "../../../stdafx.h"
#define DETLA_TIME 0.0016


Kranker3D::Camera::Camera(int width, int height)
{
	// matrix
	_projection = glm::perspective(glm::radians(90.0f), (float)width / (float)height, 0.01f, 1000000.0f);
	_view = glm::mat4(1.f);
	_view = glm::translate(_view, glm::vec3(0.0f, 0.0f, -3.0f));

	// lens
	Near = .3f;
	Far = 1000;
	FoV = 60;
	projectionType = Kranker3D::ProjectionType::PERSPECTIVE;

}


