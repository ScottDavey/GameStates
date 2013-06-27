#include "Camera.h"

Camera::Camera(void)
{
	screenWidth = 1080;
	screenHeight = 560;
	position = sf::Vector2f(0.f, 0.f);
	CameraPosition.reset(sf::FloatRect(0, 0, screenWidth, screenHeight));
	CameraPosition.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
}


Camera::~Camera(void)
{
}

sf::Vector2f Camera::GetScreenPosition() {
	return position;
}

void Camera::Update(sf::Vector2f newPos) {

	position.x = newPos.x + 40 - (screenWidth / 2);
	
	if (position.x < 0) {
		position.x = 0;
	} else if (position.x > screenWidth) {
		position.x = screenWidth;
	}

	CameraPosition.reset(sf::FloatRect(position.x, position.y, screenWidth, screenHeight));

}

void Camera::Draw(sf::RenderWindow &window) {
	window.setView(CameraPosition);
}
