#pragma once
#include "../../stdafx.h"
#include "../../glm/glm/mat4x4.hpp"

namespace Kranker3D {

	class Shader {

	private:
		GLuint programId, vertId, fragId;

		GLuint compile(std::string shader, GLenum type);
		void linkProgramme(GLuint vertexShaderId, GLuint fragmentShaderId);
		void compileStatus(GLuint shaderId);
		void linkStatus();

	public:
		Shader(std::string vertex_path, std::string fragment_path);
		Shader()=default;
		void use();
		GLuint getProgramId() { return programId; }
		void terminate();

		void setColor(const char* key, GLfloat x, GLfloat y, GLfloat z) { glUniform3f(glGetUniformLocation(programId, key), x, y, z); }
		void setFloat(const char* key, GLfloat value) { glUniform1f(glGetUniformLocation(programId, key), value); }
		void setMat4(const char* name, glm::mat4 value) { glUniformMatrix4fv(glGetUniformLocation(programId, name), 1, GL_FALSE, &value[0][0]); }
		void setVec3(const char* name, glm::vec3 value) { glUniform3fv(glGetUniformLocation(programId, name), 1,  &value[0]); }

	};
}