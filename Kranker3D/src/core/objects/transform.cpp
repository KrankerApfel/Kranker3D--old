#include "transform.h"

void Kranker3D::Transform::translate(glm::vec3 translate)
{
	_model = glm::translate(_model, translate);
	_localPosition += translate;
}

void Kranker3D::Transform::scale(glm::vec3 scale)
{
	_model = glm::scale(_model, scale);
	_localScale = glm::vec3(scale[0]*_localScale[0], scale[1] * _localScale[1], scale[2] * _localScale[2]);
}

void Kranker3D::Transform::rotate(float degree, glm::vec3 rotate)
{
	_model = glm::rotate(_model, glm::radians(degree), rotate);
	_localRotation = glm::quat(glm::radians(degree) * rotate) ;
	;
};



