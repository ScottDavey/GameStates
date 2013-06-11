#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Background
{
private:
	// Tiles
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f position;

public:
	Background(void);
	~Background(void);
	Background & operator=( const Background&);

	void Update(sf::Vector2f newPos);
	void Draw(sf::RenderWindow &window);
};

