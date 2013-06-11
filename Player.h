#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <iostream>

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
	int playerRow;
	int playerCol;

	int blRow;
	int blCol;
	int brRow;
	int brCol;
	int tlRow;
	int tlCol;
	int trRow;
	int trCol;

	// Animation Variables
	int frameWidth;
	int frameHeight;

	// Private Methods
	void ApplyPhysics(sf::Time time);
	void HandleCollision();
	float DoJump(float velocityY, float velocityX);
	float Clamp(float value, float min, float max);

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

