#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player2
{
private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::Vector2f position;
	sf::Vector2f velocity;

	float movement;
	float angle;
	float MaxMoveSpeed;
	float MaxFallSpeed;
	float GravityAcceleration;

	std::vector<std::vector<float>> collisionMapLocal;
	sf::IntRect testRect;

	void ApplyPhysics(float time);
	void HandleCollision();
	void setRectangle(sf::RectangleShape &rect, sf::Vector2f pos, sf::Vector2f size, sf::Color outline, float border);
	float Clamp(float value, float min, float max);

public:
	Player2(void);
	~Player2(void);

	void Initialize(std::vector<std::vector<float>> &collisionMap);
	void Update(sf::Time gameTime);
	void Draw(sf::RenderWindow &window);
};

