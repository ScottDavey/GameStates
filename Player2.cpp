#include "Player2.h"


Player2::Player2(void)
{

	if (!playerTexture.loadFromFile("Content/Images/VectorBased/player.png")) {
		std::cout << "No Player" << std::endl;
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(20.f, 20.f);
	
	position = sf::Vector2f(40.f, -200.f);
	velocity = sf::Vector2f(0.f, 0.f);
	movement = 0.f;
	angle = 0.f;
	MaxMoveSpeed = 400.f;
	MaxFallSpeed = 1000.f;
	GravityAcceleration = 4500.f;

}


Player2::~Player2(void)
{
}

void Player2::Initialize(std::vector<std::vector<float>> &collisionMap) {
	this->collisionMapLocal = collisionMap;
}

void Player2::Update(sf::Time time) {
	
	// Horizontal Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movement = -1.f;
		angle -= time.asSeconds() * 1200;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		angle += time.asSeconds() * 1200;
		movement = 1.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		// Reset player's position
		position = sf::Vector2f(40.f, -200.f);
	}

	ApplyPhysics(time.asSeconds());

	// Reset movement
	movement = 0.f;

}

void Player2::ApplyPhysics(float gameTime) {

	position.x += MaxMoveSpeed * gameTime * movement;
	velocity.y = Clamp(velocity.y + GravityAcceleration * gameTime, -MaxFallSpeed , MaxFallSpeed);
	position.y += velocity.y * gameTime;
	//position = sf::Vector2f((float)floor(position.x), (float)floor(position.y));

	playerSprite.setRotation(angle);

	HandleCollision();

}

void Player2::HandleCollision() {

	float b, y;

	// Screen Bounds
	if (position.x - 20.f < 0.f) {
		angle = 0;
		position.x = 20.f;
	} else if (position.x + 20.f > 1080.f) {
		angle = 0;
		position.x = 1060.f;
	}

	// Loop through collision points to see if there are any collidable lines at player's x
	for (int i = 0; i < collisionMapLocal.size(); i++) {
		if (position.x > collisionMapLocal[i][0] && position.x < collisionMapLocal[i + 1][0]) {
			// We're over a colliding line
			// Now we attempt 2 formulas: b = (((y2 - y1)/(x2 - x1))*x1-y1) * -1 to find b in this equation: y = mx + b
			// Second equation is: y = ((y2 - y1)/(x2 - x1))xp + b (or, y = mx + b)

			// Find b (b = y - mx)
			b = collisionMapLocal[i][1] - ((collisionMapLocal[i+1][1] - collisionMapLocal[i][1]) / (collisionMapLocal[i+1][0] - collisionMapLocal[i][0])) * collisionMapLocal[i][0];
			// Find y (y = mx + b)
			y = ((collisionMapLocal[i+1][1] - collisionMapLocal[i][1]) / (collisionMapLocal[i+1][0] - collisionMapLocal[i][0])) * position.x + b;

			// Perform collision if necessary
			if (position.y + 20 == y || (position.y + 20 > y && position.y < y + 20.f)) {
				position.y = y - 20;
			}

		}
	}

}

void Player2::setRectangle(sf::RectangleShape &rect, sf::Vector2f pos, sf::Vector2f size, sf::Color outline, float border) {
	rect.setPosition(pos);
	rect.setSize(size);
	rect.setFillColor(sf::Color(255, 255, 255, 0));
	rect.setOutlineColor(outline);
	rect.setOutlineThickness(border);
}


float Player2::Clamp(float value, float min, float max) {
	return value < min ? min : (value > max ? max : value);
}

void Player2::Draw(sf::RenderWindow &window) {
	playerSprite.setPosition(position);
	window.draw(playerSprite);
}
