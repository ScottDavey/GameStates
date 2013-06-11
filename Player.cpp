#include "Player.h"


Player::Player(void) { }

Player::~Player(void) { }

void Player::Initialize(std::vector<std::vector<Tile>> &tiles) {

	this->tiles = tiles;

	// Initialize our player texture/sprite
	if (!texture.loadFromFile("Content/Images/Ball.png")) {
		std::cout << "No ball" << std::endl;
	}
	sprite.setTexture(texture);

	position = sf::Vector2f(19.f, 642.f);
	velocity = sf::Vector2f(0.f, 0.f);

	MoveAcceleration	= 7500.0f;
	MaxMoveSpeed		= 100.f;
	GroundDragFactor	= 0.11f;
	AirDragFactor		= 0.65f;

	MaxJumpTime			= 0.25f;
	JumpLaunchVelocity	= -2000.0f;
	GravityAcceleration = 3500.0f;
	MaxFallSpeed		= 150.0f;
	JumpControlPower	= 0.14f;

	isJumping = false;
	wasJumping = false;
	isOnGround = true;

	frameWidth = texture.getSize().x;
	frameHeight = texture.getSize().y;

	angle = 0.f;

}

void Player::Update(sf::Time time) {

	float gameTime = time.asSeconds();
	
	// Vertical Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		position.y += -1 * gameTime * 750;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		position.y += 1 * gameTime * 750;
	}

	// Horizontal Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movement = -1.0f;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		movement = 1.0f;
	}

	// Jumping
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		isJumping = true;
	}

	ApplyPhysics(time);

	movement = 0.f;
	isJumping = false;

}

void Player::ApplyPhysics(sf::Time time) {
	
	float gameTime = time.asSeconds() * 10;
	sf::Vector2f previousPosition = position;

	// Base velocity is a combination of horizontal movement control and
	// acceleration downward due to gravity
	velocity.x += movement * MoveAcceleration * gameTime;
	//velocity.y = Clamp(velocity.y + GravityAcceleration * gameTime, -MaxFallSpeed , MaxFallSpeed);

	velocity.y = DoJump(velocity.y, gameTime);

	// Apply drag factor
	if (isOnGround) {
		velocity.x *= GroundDragFactor;
	} else {
		velocity.x *= AirDragFactor;
	}

	// Prevent player from running faster than top speed
	velocity.x = Clamp(velocity.x, -MaxMoveSpeed, MaxMoveSpeed);

	// Apply velocity
	position += velocity * gameTime;
	position = sf::Vector2f((float)floor(position.x), (float)floor(position.y));

	// Collision
	HandleCollision();

}

void Player::HandleCollision() {

	playerRow = floor((position.y + frameHeight) / 40);
	playerCol = (int)((position.x + (frameWidth / 2)) / 40);

	blRow = floor((position.y + frameHeight) - 10) / 40;
	blCol = floor(position.x + 25) / 40;

	brRow = floor((position.y + frameHeight) - 10) / 40;
	brCol = floor((position.x + frameWidth) - 25) / 40;

	tlRow = floor(position.y + 15) / 40;
	tlCol = floor(position.x + 26) / 40;

	trRow = floor(position.y + 15) / 40;
	trCol = floor((position.x + frameWidth) - 26) / 40;

	if (blRow < tiles.size() && blCol < tiles[0].size() && 
		tlRow < tiles.size() && tlCol < tiles[0].size()) {

		// Top
		if(tiles[tlRow][tlCol].GetCollision() == "Impassable" || tiles[trRow][trCol].GetCollision() == "Impassable")
		{
			position.y = tiles[tlRow][tlCol].GetY();
		}
		
		// Bottom
		if(tiles[blRow][blCol].GetCollision() != "Passable" || tiles[brRow][brCol].GetCollision() != "Passable")
		{
			//isOnGround = true;
			position.y = tiles[blRow][blCol].GetY() - (frameHeight - 1);
		}
		else
		{
			//isOnGround = false;
		}

	}

	// Screen Bounds
	if (position.x < 0.f) {
		position.x = 0.f;
	} else if (position.x > 2541.f) {
		position.x = 2541.f;
	} else if (position.y < 0.f) {
		position.y = 0.f;
	}
}

float Player::DoJump(float velocityY, float gameTime) {

	// If player wants to jump
	if (isJumping) {
		
		// Begin or continue a jump
		if ((!wasJumping && isOnGround) || jumpTime > 0.f) {
			
			jumpTime =+ gameTime;

		}

		// If we are in the ascent of the jump
		if (0.f < jumpTime && jumpTime <= MaxJumpTime) {
			
			// Fully override the vertical velocity with a power curve that gives the player
			// more control over the top of the jump
			velocityY = JumpLaunchVelocity * (1.f - (float)pow(jumpTime / MaxJumpTime, JumpControlPower));

		} else {
			
			// Reached the apex of the jump
			jumpTime = 0.f;

		}

	} else {
		
		// Continues not jumping or cancels a jump in progress
		jumpTime = 0.f;

	}

	wasJumping = isJumping;

	return velocityY;

}

float Player::Clamp(float value, float min, float max) {
	return value < min ? min : (value > max ? max : value);
}

void Player::Draw(sf::RenderWindow &window) {
	sprite.setPosition(position);
	window.draw(sprite);
}
