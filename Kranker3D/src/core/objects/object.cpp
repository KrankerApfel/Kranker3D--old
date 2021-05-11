#include "Object.h"

Kranker3D::Object::Object()
{
	mesh = Mesh();
	shader = Shader();
	texture = 0;
}

Kranker3D::Object::Object(Mesh mesh, Shader shader, GLuint texture)
{
	this->mesh = mesh;
	this->shader = shader;
	this->texture = texture;
}

Kranker3D::Object::Object(const Object& obj)
{
	this->mesh = obj.getMesh();
	this->shader = obj.getShader();
	this->texture = obj.getTexture();
}

void Kranker3D::Object::Draw()
{
	this->shader.use();
	this->mesh.draw();
}
