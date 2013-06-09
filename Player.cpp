#include "Player.h"


Player::Player(void)
{
	if (!texture.loadFromFile("Content/Images/Ball.png")) {
		std::cout << "No ball" << std::endl;
	}
	sprite.setTexture(texture);
	position = sf::Vector2f(20.f, 600.f);
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
	
	/*// Vertical Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		position.y -= 4;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		position.y += 4;
	}

	// Horizontal Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		position.x -= 15;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		position.x += 15;
	}*/

}

void Player::Draw(sf::RenderWindow &window) {
	sprite.setPosition(position);
	window.draw(sprite);
}
