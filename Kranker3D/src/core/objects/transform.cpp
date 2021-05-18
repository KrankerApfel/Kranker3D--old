#include "transform.h"

Kranker3D::Transform::Transform()
{
	position = glm::vec3(0.);
	scale = glm::vec3(1.);
	rotation = glm::vec3(0.);

}

glm::vec3 Kranker3D::Transform::getForward() const
{
	float x = rotation.x;
	float y = rotation.y;
	float z = rotation.z;
	float w = rotation.w;

	return glm::normalize(glm::vec3(2 * (x * z + w * y),
								    2 * (y * z - w * x),
							        1 - 2 * (x * x + y * y)));
}

void Kranker3D::Transform::translate(glm::vec3 translate)
{

	position += translate;
}

void Kranker3D::Transform::rescale(float scale_factor)
{
	scale = glm::vec3(scale_factor);
}

void Kranker3D::Transform::rotate(float degree, glm::vec3 rotate)
{
	rotation = glm::quat(glm::radians(degree) * rotate);
}
void  Kranker3D::Transform::lerp(glm::vec3 origin, glm::vec3 goal, float step)
{
	position = ( origin * (1.f - step) + goal * step);
}




