#include "Background.h"


Background::Background(void)
{

	// Tiles
	if (!texture.loadFromFile("Content/Images/Tileset_SpriteSheet_Layer3.png")) {
		std::cout << "Couldn't load tileset" << std::endl;
	}
	sprite.setTexture(texture);

	position = sf::Vector2f(0.f, 0.f);

}


Background::~Background(void)
{
}

void Background::Update(sf::Vector2f newPos) {

	position.x = newPos.x + 40 - (1280 / 2);
	
	if (position.x < 0) {
		position.x = 0;
	} else if (position.x > 1280) {
		position.x = 1280;
	}

	sprite.setPosition(position.x * 0.9f, 0.f);

}

void Background::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
}