#pragma once

#include "../../glm/glm/glm.hpp"
#include "../../glm/glm/gtc/matrix_transform.hpp"
#include <string>
#include <vector>
#include "../../../stdafx.h"
#include "shader.h"
using namespace std;

namespace Kranker3D {

	struct Vertex {
		glm::vec3 Position{};
		glm::vec3 Normal{};
		glm::vec2 TexCoords{};
		//glm::vec3 Tangent{};
		//glm::vec3 Bitangent{};
	};

	class Mesh {

	public:
		vector<Vertex> vertices;
		vector<unsigned int> indices;
		unsigned int VAO;
		glm::vec3 color;

		Mesh();
		Mesh(const vector<Vertex> vertices, const vector<unsigned int> indices);
		void draw();
		void terminate();
		inline void setTransform(glm::mat4 t) { transform = t; }
		inline glm::mat4 getTransform() { return transform; }
		inline void rotate(float degree, glm::vec3 rotate) { transform = glm::rotate(transform, glm::radians(degree), rotate); };
		inline void scale(glm::vec3 scale) { transform = glm::scale(transform, scale); }
		inline void translate(glm::vec3 translate) { transform = glm::translate(transform, translate); }
	private:
		unsigned int VBO, EBO;
		void initRenderingData();
		glm::mat4 transform;

	};
}