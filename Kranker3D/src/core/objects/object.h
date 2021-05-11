#pragma once
#include "../rendering/mesh.h"
#include "../rendering/shader.h"
namespace Kranker3D {

	class Object
	{
		private:
			Mesh mesh;
			Shader shader;
			GLuint texture;
		public:
			Object();
			Object(Mesh mesh, Shader shader, GLuint texture);
			Object(const Object& obj);


			Mesh getMesh() const { return mesh; }
			Shader getShader() const { return shader; }
			GLuint getTexture() const { return texture; }

			void setMesh(Mesh mesh) { this->mesh = mesh; }
			void setShader(Shader shader) { this->shader = shader; }
			void setTexture(GLuint texture) { this->texture = texture; }

			void Draw();
	};

}