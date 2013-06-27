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

	position = sf::Vector2f(30.f, 200.f);
	velocity = sf::Vector2f(0.f, 0.f);

	MoveAcceleration	= 400.0f;
	MaxMoveSpeed		= 400.f;
	GroundDragFactor	= 0.58f;
	AirDragFactor		= 0.65f;


	MaxJumpTime			= 0.33f;
	JumpLaunchVelocity	= -3000.0f;
	GravityAcceleration = 4500.0f;
	MaxFallSpeed		= 1500.0f;
	JumpControlPower	= 0.18f;

	isJumping = false;
	wasJumping = false;
	isOnGround = true;

	frameWidth = texture.getSize().x;
	frameHeight = texture.getSize().y;

	angle = 0.f;

	playerBox = sf::IntRect(position.x, position.y, frameWidth, frameHeight);
	topLeft = sf::IntRect(position.x, position.y, frameWidth, frameHeight);
	topRight = sf::IntRect(position.x, position.y, frameWidth, frameHeight);
	bottomLeft = sf::IntRect(position.x, position.y, frameWidth, frameHeight);
	bottomRight = sf::IntRect(position.x, position.y, frameWidth, frameHeight);
	setRectangle(left, sf::Vector2f(0.f, 0.f), sf::Vector2f(frameWidth, frameHeight), sf::Color(255, 0, 0), 1.f);
	setRectangle(right, sf::Vector2f(0.f, 0.f), sf::Vector2f(frameWidth, frameHeight), sf::Color(0, 255, 0), 1.f);

}

void Player::Update(sf::Time time) {

	float gameTime = time.asSeconds();

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

	ApplyPhysics(gameTime);

	movement = 0.f;
	isJumping = false;

}

void Player::ApplyPhysics(float gameTime) {

	// Base velocity is a combination of horizontal movement control and
	// acceleration downward due to gravity
	velocity.y = Clamp(velocity.y + GravityAcceleration * gameTime, -MaxFallSpeed , MaxFallSpeed);
	velocity.y = DoJump(velocity.y, gameTime);	

	// Apply velocity
	position.x += MaxMoveSpeed * gameTime * movement;
	position.y += velocity.y * gameTime;
	position = sf::Vector2f((float)floor(position.x), (float)floor(position.y));

	// Collision
	HandleCollision();

	/******** UNUSED *********
	velocity.x += MoveAcceleration * gameTime * movement;
	position += velocity * gameTime;
	if (isOnGround) {
		velocity.x *= GroundDragFactor;
	} else {
		velocity.x *= AirDragFactor;
	}
	// Prevent player from running faster than top speed
	velocity.x = Clamp(velocity.x, -MaxMoveSpeed, MaxMoveSpeed);
	********************/
}

void Player::HandleCollision() {

	// x = column, y = row

	// Set the player's collision box
	playerBox = sf::IntRect(position.x, position.y, frameWidth, frameHeight);
	
	// If player is jumping we only need to check for collision from above. Otherwise we're always 
	// checking for collision from below due to gravity.
	/*if (isJumping || wasJumping) {
		vertLeftRowCol = sf::Vector2i(floor(position.x / frameWidth), floor(position.y / frameHeight));
		vertRightRowCol = sf::Vector2i(ceil(position.x / frameWidth), floor(position.y / frameHeight));	
	} else {
		vertLeftRowCol = sf::Vector2i(floor(position.x / frameWidth), ceil(position.y / frameHeight));
		vertRightRowCol = sf::Vector2i(ceil(position.x / frameWidth), ceil(position.y / frameHeight));
	}*/

	topLeftRowCol = sf::Vector2i(floor(position.x / frameWidth), floor(position.y / frameHeight));
	topRightRowCol = sf::Vector2i(ceil(position.x / frameWidth), floor(position.y / frameHeight));
	bottomLeftRowCol = sf::Vector2i(floor(position.x / frameWidth), ceil(position.y / frameHeight));
	bottomRightRowCol = sf::Vector2i(ceil(position.x / frameWidth), ceil(position.y / frameHeight));

	// Set Collision rectangles
	topLeft = sf::IntRect(topLeftRowCol.x * frameWidth, topLeftRowCol.y * frameWidth, frameWidth, frameHeight);
	topRight = sf::IntRect(topRightRowCol.x * frameWidth, topRightRowCol.y * frameWidth, frameWidth, frameHeight);
	bottomLeft = sf::IntRect(bottomLeftRowCol.x * frameWidth, bottomLeftRowCol.y * frameWidth, frameWidth, frameHeight);
	bottomRight = sf::IntRect(bottomRightRowCol.x * frameWidth, bottomRightRowCol.y * frameWidth, frameWidth, frameHeight);

	// Debug: rectangle shapes for visual verification
	left.setPosition(bottomLeft.left, bottomLeft.top);
	right.setPosition(bottomRight.left, bottomRight.top);

	// Make sure array is in bounds, then check for collision (needs redoing)
	if (topLeftRowCol.x < tiles[0].size() && topLeftRowCol.y < tiles.size() &&
		topRightRowCol.x < tiles[0].size() && topRightRowCol.y < tiles.size()) {
		
		// Y Collision: Ceiling
		if (tiles[topLeftRowCol.y][topLeftRowCol.x].GetCollision() == "Platform" && playerBox.intersects(topLeft) || tiles[topRightRowCol.y][topRightRowCol.x].GetCollision() == "Platform" && playerBox.intersects(topRight) ) {
			position.y = tiles[topLeftRowCol.y][topLeftRowCol.x].GetY() + 40;
		}

		// Y Collision: Floor
		if (tiles[bottomLeftRowCol.y][bottomLeftRowCol.x].GetCollision() == "Platform" && playerBox.intersects(bottomLeft) || tiles[bottomRightRowCol.y][bottomRightRowCol.x].GetCollision() == "Platform" && playerBox.intersects(bottomRight)) {
			position.y = tiles[bottomLeftRowCol.y][bottomLeftRowCol.x].GetY() - frameHeight;
		} else {
			isOnGround = true;
		}
	} else {
		// If out of bounds, set player to specific location. (primarily if player falls through the floor)
		position.y = 480.f;
	}

	// Screen Bounds
	if (position.x < 0.f) {
		position.x = 0.f;
	} else if (position.x > 2122.f) {
		position.x = 2122.f;
	}
}

float Player::DoJump(float velocityY, float gameTime) {

	// If player wants to jump
	if (isJumping) {
		
		// Begin or continue a jump
		if ((!wasJumping && isOnGround) || jumpTime > 0.f) {
			
			jumpTime += gameTime;

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

void Player::setRectangle(sf::RectangleShape &rect, sf::Vector2f pos, sf::Vector2f size, sf::Color outline, float border) {
	rect.setPosition(pos);
	rect.setSize(size);
	rect.setFillColor(sf::Color(255, 255, 255, 0));
	rect.setOutlineColor(outline);
	rect.setOutlineThickness(border);
}

void Player::Draw(sf::RenderWindow &window) {

	/************************
		Drawing a line to the screen - sf::Vertex
	
		sf::Vertex line[] = {
			sf::Vertex(sf::Vector2f(10.f, 10.f), sf::Color::Red, sf::Vector2f(10.f, 10.f)),
			sf::Vertex(sf::Vector2f(20.f, 40.f), sf::Color::Red, sf::Vector2f(20.f, 40.f))
		};
		window.draw(line, 2, sf::Lines);
	
	************************

		Drawing a line to the screen - sf::VertexArray

		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0].position = sf::Vector2f(10.f, 10.f);
		lines[1].position = sf::Vector2f(20.f, 40.f);

		window.draw(lines);

	************************/

	sprite.setPosition(position);
	window.draw(sprite);
	/*window.draw(left);
	window.draw(right);*/

}
