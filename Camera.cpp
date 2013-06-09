#include "Camera.h"

Camera::Camera(void)
{
	screenWidth = 1280;
	screenHeight = 720;
	position = sf::Vector2f(0.f, 0.f);
	CameraPosition.setViewport(sf::FloatRect(position, sf::Vector2f(screenWidth, screenHeight)));
}


Camera::~Camera(void)
{
}

void Camera::Update(sf::Vector2f newPos) {
	position = sf::Vector2f(0.f, 0.f);
	
	if (position.x < 0) {
		position.x = 0;
	}
	if (position.y < 0) {
		position.y = 0;
	}

	CameraPosition.setViewport(sf::FloatRect(position, sf::Vector2f(screenWidth, screenHeight)));

}

void Camera::Draw(sf::RenderWindow &window) {
	window.setView(CameraPosition);
}
