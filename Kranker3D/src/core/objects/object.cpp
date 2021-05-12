#include "Object.h"

Kranker3D::Object::Object()
{
	_transform = Transform();
}

Kranker3D::Object::Object(Transform t)
{
	_transform =t;

}

Kranker3D::Object::Object(const Object& obj)
{
	
	_transform =  obj._transform;

}


