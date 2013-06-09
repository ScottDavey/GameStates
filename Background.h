#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <sstream>

#define TileWidth 40
#define TileHeight 40

class Background
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
	Background(void);
	~Background(void);
	Background & operator=( const Background&);

	void Update(sf::Time time);
	void Draw(sf::RenderWindow &window);
};

