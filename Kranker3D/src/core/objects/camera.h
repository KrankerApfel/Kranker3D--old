#pragma once
#include <iostream>
#include <glad/glad.h>
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/string_cast.hpp"
#include "../../core/objects/transform.h"

namespace Kranker3D
{

	enum class ProjectionType {PERSPECTIVE = 0 , ORTHOGONAL = 1};

	class Camera {
	
	private:

		// matrix
		glm::mat4 _projection;
		glm::mat4 _view;
		
		Transform _transform;



	public:
		// lens settings
		float Near, Far, FoV;
		ProjectionType projectionType;

		Camera(int width, int height);

		//getter
		inline glm::mat4 getView() const { return _view; }
		inline glm::mat4 getProj() const { return _projection; }
		inline Transform* getTransform() { return &_transform; }


		//setter
		inline void setView(glm::mat4 newView) { _view = newView; }
		

	


	};
}