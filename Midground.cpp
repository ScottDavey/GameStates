#include "Midground.h"


Midground::Midground(void)
{

	// Tiles
	if (!texture.loadFromFile("Content/Images/ArtBased/background.png")) {
		std::cout << "Couldn't load tileset" << std::endl;
	}
	sprite.setTexture(texture);

	position = sf::Vector2f(0.f, 0.f);

}


Midground::~Midground(void)
{
}


void Midground::Update(sf::Vector2f newPos) {

	position.x = newPos.x + 40 - (1080 / 2);
	
	if (position.x < 0) {
		position.x = 0;
	} else if (position.x > 1080) {
		position.x = 1080;
	}

	sprite.setPosition(position.x * 0.9f, 0.f);

}

void Midground::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
}
