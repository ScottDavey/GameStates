#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <sstream>

#define TileWidth 40
#define TileHeight 40

class Midground
{
private:

	// Tiles
	sf::Texture tileSpriteSheet;

	sf::IntRect tile1Rect;
	sf::IntRect tile2Rect;
	sf::IntRect tile3Rect;

	std::vector<std::vector<char>> MapVector;
	std::vector<std::vector<Tile>> TileVector;

	void LoadMap(const char *path);
	Tile LoadTile(char tileType, int x, int y);

public:
	Midground(void);
	~Midground(void);
	Midground & operator=( const Midground&);

	void Update(sf::Time time);
	void Draw(sf::RenderWindow &window);
};

