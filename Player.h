#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <iostream>
#include <sstream>

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<std::vector<Tile>> tiles;

	// Physics Variables
	float movement;
	float angle;
	float previousBottom;

	float MoveAcceleration;
	float MaxMoveSpeed;
	float GroundDragFactor;
	float AirDragFactor;

	float MaxJumpTime;
	float JumpLaunchVelocity;
	float GravityAcceleration;
	float MaxFallSpeed;
	float JumpControlPower;

	bool isOnGround;
	bool isJumping;
	bool wasJumping;
	float jumpTime;

	// Collision Variables
	sf::Vector2i topLeftRowCol;
	sf::Vector2i topRightRowCol;
	sf::Vector2i bottomLeftRowCol;
	sf::Vector2i bottomRightRowCol;
	sf::Vector2i horLeftRowCol;
	sf::Vector2i horRightRowCol;
	sf::IntRect playerBox;
	sf::IntRect topLeft;
	sf::IntRect topRight;
	sf::IntRect bottomLeft;
	sf::IntRect bottomRight;
	sf::IntRect horTop;
	sf::IntRect horBottom;

	sf::RectangleShape left;
	sf::RectangleShape right;

	// Animation Variables
	int frameWidth;
	int frameHeight;

	// General Variables
	bool keyLock;

	// Private Methods
	void ApplyPhysics(float gameTime);
	void HandleCollision();
	float DoJump(float velocityY, float velocityX);
	float Clamp(float value, float min, float max);
	void setRectangle(sf::RectangleShape &rect, sf::Vector2f position, sf::Vector2f size, sf::Color outline, float border);

public:
	Player(void);
	~Player(void);
	Player & operator=(const Player&);

	sf::Vector2f position;
	sf::Vector2f velocity;

	void Initialize(std::vector<std::vector<Tile>> &tiles);
	void Update(sf::Time time);
	void Draw(sf::RenderWindow &window);
};

