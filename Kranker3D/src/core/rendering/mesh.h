#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <vector>
#include "../../stdafx.h"
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
	
	private:
		unsigned int VBO, EBO, IBO;
		void initRenderingData();

	};
}