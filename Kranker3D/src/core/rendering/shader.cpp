#include "../../stdafx.h"
#include "../io/file.h"
#include "shader.h"


GLuint Kranker3D::Shader::compile(std::string shader, GLenum type)
{
	GLuint id = glCreateShader(type);
	const char* shaderCode = shader.c_str();

	glShaderSource(id, 1, &shaderCode, NULL);
	glCompileShader(id);

	this->compileStatus(id);

	return id;
}

void Kranker3D::Shader::linkProgramme(GLuint vertexShaderId, GLuint fragmentShaderId)
{
	programId = glCreateProgram();
	if (programId == 0 || programId == GL_INVALID_OPERATION)
		spdlog::warn("--- SHADER : Not able to create the shader object properly.\n Program ID :  {}", programId);
	vertId = vertexShaderId;
	fragId = fragmentShaderId;
	glAttachShader(programId, vertId);
	glAttachShader(programId, fragId);
	glLinkProgram(programId);

	this->linkStatus();

}

void Kranker3D::Shader::compileStatus(GLuint shaderId)
{
	int success;
	char infoLog[512];
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
		spdlog::warn("--- SHADER : Shader {} did not compile ! \n===\n%s\n===\n {}", shaderId, infoLog);
	}
	else
	{
		spdlog::info("--- SHADER : Shader {} loaded and compiled proprely\n", shaderId);
	}
}

void Kranker3D::Shader::linkStatus()
{
	int success;
	GLint linkStatus;
	char infoLog[512];
	glGetProgramiv(programId, GL_LINK_STATUS, &linkStatus);
	if (!linkStatus)
	{
		glGetProgramInfoLog(programId, 512, NULL, infoLog);
		spdlog::error("--- SHADER : Program linking failed : \n===\n%s\n===\n {}", infoLog);
	}
	else {
		spdlog::info("--- SHADER : Program {} link properly\n", programId);
		glGetProgramiv(programId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(programId, 512, NULL, infoLog);
			spdlog::error("--- SHADER : Program did not compile : \n===\n%s\n===\n {}", infoLog);
		}
		else
		{
			spdlog::info("--- SHADER : Program {} loaded and compiled proprely.\n", programId);
		}
	}

}

Kranker3D::Shader::Shader(std::string vertex_path, std::string fragment_path)
{
	programId = 0;
	GLuint v_id = this->compile(File::read(vertex_path), GL_VERTEX_SHADER);
	GLuint f_id = this->compile(File::read(fragment_path), GL_FRAGMENT_SHADER);
	this->linkProgramme(v_id, f_id);
}

void Kranker3D::Shader::use()
{
	glUseProgram(programId);
}

void Kranker3D::Shader::terminate()
{
	glDetachShader(programId, vertId);
	glDetachShader(programId, fragId);
	glDeleteShader(vertId);
	glDeleteShader(fragId);
	glDeleteProgram(programId);
}
