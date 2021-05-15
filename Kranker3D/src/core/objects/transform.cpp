#include "transform.h"

Kranker3D::Transform::Transform()
{
	_position = glm::vec3(0.);
	_scale = glm::vec3(1.);
	_rotation = glm::vec3(0.);

}

glm::vec3 Kranker3D::Transform::getForward() const
{
	float x = _rotation.x;
	float y = _rotation.y;
	float z = _rotation.z;
	float w = _rotation.w;

	return glm::normalize(glm::vec3(2 * (x * z + w * y),
								    2 * (y * z - w * x),
							        1 - 2 * (x * x + y * y)));
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
	_rotation = glm::quat(glm::radians(degree) * rotate);
}
void  Kranker3D::Transform::lerp(glm::vec3 origin, glm::vec3 goal, float step)
{
	_position = ( origin * (1.f - step) + goal * step);
}




