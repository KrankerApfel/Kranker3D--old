#pragma once
#include "../rendering/mesh.h"
#include "../rendering/shader.h"
#include "../objects/transform.h"

namespace Kranker3D {

	class Object
	{
	private:
		Transform _transform;

	public:
		Object();
		Object(Transform transform);
		Object(const Object& obj);
		inline Transform getTransform() const { return  _transform; }


	};

}