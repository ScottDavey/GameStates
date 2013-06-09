#pragma once
#include <SFML/Graphics.hpp>
#include "BaseClass.h"
#include "Camera.h"
#include "Player.h"
#include "Midground.h"
#include "Background.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <sstream>

#define TileWidth 40
#define TileHeight 40

class Level : public BaseClass
{
private:
	sf::RenderWindow &window;

	Camera camera;

	// Players
	Player player;

	// Tiles
	sf::Texture tileSpriteSheet;

	sf::IntRect tile1Rect;
	sf::IntRect tile2Rect;
	sf::IntRect tile3Rect;

	std::vector<std::vector<char>> MapVector;
	std::vector<std::vector<Tile>> TileVector;

	// Layers
	Midground midground;
	Background background;

	void LoadMap(const char *path);
	Tile LoadTile(char tileType, int x, int y);

public:
	Level(sf::RenderWindow &window);
	~Level(void);
	Level & operator=( const Level&);

	void Update(sf::Time time);
	void Draw(sf::Time time);

};