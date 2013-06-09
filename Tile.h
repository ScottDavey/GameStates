#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile
{
private:
	sf::Texture texture;
	sf::IntRect rect;
	std::string collision;

	int x;
	int y;

public:
	Tile(sf::Texture& image, sf::IntRect rect, int x, int y, std::string collision, std::string tileType);
	Tile(int x, int y, std::string collision, std::string tileType);
	Tile(void);
	~Tile(void);

	std::string tileType;

	int GetX();
	int GetY();
	std::string GetTileType();
	std::string GetCollision();
	sf::Texture& GetTexture();
	sf::IntRect GetRect();

};

