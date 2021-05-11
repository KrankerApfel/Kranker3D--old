#include "Object.h"

Kranker3D::Object::Object()
{
	transform = Transform();
}

Kranker3D::Object::Object(Transform t)
{
	transform =t;

}

Kranker3D::Object::Object(const Object& obj)
{
	
	transform =  obj.transform;

}


