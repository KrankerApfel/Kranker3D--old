#pragma once
#include "../rendering/mesh.h"
#include "../rendering/shader.h"
#include "../objects/transform.h"

namespace Kranker3D {

	class Object
	{

	public:
		Transform transform;

		Object();
		Object(Transform transform);
		Object(const Object& obj);

	};

}