#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <iostream>

class Midground
{
private:

	// Tiles
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f position;

public:
	Midground(void);
	~Midground(void);
	Midground & operator=( const Midground&);

	void Update(sf::Vector2f newPos);
	void Draw(sf::RenderWindow &window);
};

