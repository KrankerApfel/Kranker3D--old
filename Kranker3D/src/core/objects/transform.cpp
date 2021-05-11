#include "transform.h"

Kranker3D::Transform::Transform()
{
	_position = glm::vec3(0.);
	_scale = glm::vec3(1.);
	_rotation = glm::vec3(0.);
	
}

void Kranker3D::Transform::translate(glm::vec3 translate)
{
	_position += translate;
}

void Kranker3D::Transform::scale(glm::vec3 scale)
{
	_scale = scale;
}

void Kranker3D::Transform::rotate(float degree, glm::vec3 rotate)
{
	_rotation = glm::quat(glm::radians(degree) * rotate) ;
};



