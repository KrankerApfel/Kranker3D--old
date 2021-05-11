#include "Camera.h"
#include "../../../stdafx.h"
#define DETLA_TIME 0.0016
void Kranker3D::Camera::updateFront()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);
}

void Kranker3D::Camera::updateCamMouse(float yaw_offset, float pitch_offset)
{
	setYaw(yaw + yaw_offset * sensibility);
	setPitch(pitch + pitch_offset * sensibility);
	updateFront();
}

Kranker3D::Camera::Camera(int width, int height)
{
	projection = glm::perspective(glm::radians(90.0f), (float)width / (float)height, 0.01f, 1000000.0f);

	view = glm::mat4(1.f);

	position = glm::vec3(0.0f, 0.0f, 0.0f);
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	speed = 5.f;

	sensibility = 0.5f;

	yaw = -90.f;
	pitch = 0.f;

	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
}

void Kranker3D::Camera::setPitch(float p)
{
	if (p > 89.f)
		pitch = 89.f;
	else if (p < -89.f)
		pitch = -89.f;
	else pitch = p;
}

void Kranker3D::Camera::update(float mouse_offsetX, float mouse_offsetY)
{


	//glm::vec3 newpos(0.f);

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	//	newpos += 0.0016f * glm::vec3(front);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	//	newpos -= 0.0016f * glm::vec3(front);

	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	//	newpos += 0.0016f * glm::normalize(glm::cross(front, up));
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	//	newpos -= 0.0016f * glm::normalize(glm::cross(front, up));
	//}
	//this->position += newpos;

	//updateCamMouse(mouse_offsetX, mouse_offsetY);
}
