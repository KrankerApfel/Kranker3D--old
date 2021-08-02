#pragma once
#include <memory>
#include "../rendering/mesh.h"
#include "../rendering/shader.h"
#include "../objects/transform.h"

namespace Kranker3D {

	class Object
	{
	protected :
		std::shared_ptr<Transform> _transform;

	public:

		Object();
		Object(std::shared_ptr<Transform> transform);
		Object(const Object& obj);
		std::shared_ptr<Transform> const getTransform() { return _transform; }

	};

}