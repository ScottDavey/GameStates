#include "Player.h"


Player::Player(void)
{

	// Initialize our player texture/sprite and origin/angle (for rotation)
	if (!texture.loadFromFile("Content/Images/Ball.png")) {
		std::cout << "No ball" << std::endl;
	}
	sprite.setTexture(texture);
	position = sf::Vector2f(19.f, 659.f);
	sprite.setOrigin(19.f, 19.f);
	angle = 0.f;

	// Bounding box
	/*box.setSize(sf::Vector2f(38.f, 38.f));
	box.setFillColor(sf::Color(255, 255, 255, 0));
	box.setOutlineColor(sf::Color::Blue);
	box.setOutlineThickness(1.f);
	box.setOrigin(19.f, 19.f);
	box.setPosition(sf::Vector2f(0.f, 659.f));*/
}


Player::~Player(void)
{
}

void Player::setPosition(sf::Vector2f position) {
	position = position;
}

sf::Vector2f Player::getPosition() {
	return position;
}

void Player::Update(sf::Time time) {

	float gameTime = time.asSeconds();
	
	// Vertical Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		position.y += -1 * gameTime * 750;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		position.y += 1 * gameTime * 750;
	}

	// Horizontal Movement (with rotation of ball)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		position.x += -1 * gameTime * 1000;
		if (angle < 360.f && position.x > 19.f) {
			sprite.setRotation(angle += -1 * gameTime * 3000);
		} else {
			angle = 0.f;
		}
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		position.x += 1 * gameTime * 1000;
		if (angle < 360.f && position.x < 2539.f) {
			sprite.setRotation(angle += 1 * gameTime * 3000);
		} else {
			angle = 0.f;
		}
	}

	// Basic collision against horizontal screen bounds
	if (position.x < 19.f) {
		position.x = 19.f;
	} else if(position.x > 2539.f) {
		position.x = 2539.f;
	}

	// Basic collision against floor top of screen
	if (position.y < 19.f) {
		position.y = 19.f;
	} else if (position.y > 659.f) {
		position.y = 659.f;
	}

	// Set the bounding box
	//box.setPosition(position);

}

void Player::Draw(sf::RenderWindow &window) {
	sprite.setPosition(position);
	window.draw(sprite);
	//window.draw(box);
}
