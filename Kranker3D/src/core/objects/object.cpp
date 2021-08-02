#include "Object.h"

Kranker3D::Object::Object()
{
	_transform = std::make_shared<Kranker3D::Transform>();
}

Kranker3D::Object::Object(std::shared_ptr<Kranker3D::Transform> t)
{
	_transform =t;

}

Kranker3D::Object::Object(const Object& obj)
{
	
	_transform =  obj._transform;

}


