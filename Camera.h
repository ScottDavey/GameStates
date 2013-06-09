#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Camera
{
private:
	int screenWidth;
	int screenHeight;

protected:
	sf::View CameraPosition;
	sf::Vector2f position;

public:
	Camera(void);
	~Camera(void);

	sf::Vector2f GetCamera();
	void Update(sf::Vector2f);
	void Draw(sf::RenderWindow &window);

};

