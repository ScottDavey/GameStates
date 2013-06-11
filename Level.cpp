#include "Level.h"


Level::Level(sf::RenderWindow &window)
	: window(window)
{

	// Tiles
	if (!tileSpriteSheet.loadFromFile("Content/Images/Tileset_SpriteSheet.png")) {
		std::cout << "Couldn't load tileset" << std::endl;
	}

	tile1Rect = sf::IntRect(0, 0, TileWidth, TileHeight);
	tile2Rect = sf::IntRect(40, 0, TileWidth, TileHeight);
	tile3Rect = sf::IntRect(80, 0, TileWidth, TileHeight);

	LoadMap("Content/Levels/1/layer1.txt");

	showGameMenu = false;
	keyLock = true;
	mouseLock = true;

}


Level::~Level(void)
{
}

void Level::LoadMap(const char *path) {
	
	std::ifstream openfile(path);
	std::vector<char> tempVector;
	std::string line;
	char tileType;

	// Store all charaters in the file to a 2D vector (MapVector)
	if (openfile.is_open()) {

		while (openfile >> tileType) {
		
			std::getline(openfile, line);

			for (int i = 0; i < line.length(); i++) {
				if (line[i] != ' ') {
					tempVector.push_back(line[i]);
				}
			}

			MapVector.push_back(tempVector);
			tempVector.clear();

		}

		openfile.close();

	} else {
		std::cout << "Unable to open file" << std::endl;
	}

	// Create and store new tiles for every character in MapVector
	std::vector<Tile> tempTileVector;

	for (int r = 0; r < MapVector.size(); ++r) {
		for (int c = 0; c < MapVector[r].size(); ++c) {
			tempTileVector.push_back(LoadTile(MapVector[r][c], c * TileWidth, r * TileHeight));
		}

		TileVector.push_back(tempTileVector);
		tempTileVector.clear();
	}

	// Clear up some stuff
	MapVector.clear();

	// Load Player
	player.Initialize(TileVector);

}

Tile Level::LoadTile(char tileType, int x, int y) {
	
	switch (tileType) {
		case '.':
			// Air Tile
			return Tile(x, y, "Passable", "A");
			break;
		case 'O':
			// Orange Tile
			return Tile(tileSpriteSheet, tile2Rect, x, y, "Platform", "O");
			break;
		case 'B':
			// Blue Tile
			return Tile(tileSpriteSheet, tile3Rect, x, y, "Impassable", "B");
			break;
		case 'G':
			// Green Tile
			return Tile(tileSpriteSheet, tile1Rect, x, y, "Platform", "G");
			break;
		default:
			// Tile not assigned so return an Air Tile
			return Tile(x, y, "Passable", "A");
			break;
	}

}

void Level::Update(sf::Time time) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !keyLock) {
		if (!showGameMenu) {
			showGameMenu = true;
		} else {
			showGameMenu = false;
		}
		keyLock = true;
	}
	
	if (showGameMenu) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		if (menu.getQuitRect().contains(mousePos) && !mouseLock) {
			menu.setQuitColor(sf::Color(0, 255, 128));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				window.close();
			}
			mouseLock = true;
		} else if (menu.getBackRect().contains(mousePos) && !mouseLock) {
			menu.setBackColor(sf::Color(0, 255, 128));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				showGameMenu = false;
			}
			mouseLock = true;
		} else {
			menu.setQuitColor(sf::Color(255, 255, 255));
			menu.setBackColor(sf::Color(255, 255, 255));
		}
	}

	camera.Update(player.position);
	background.Update(player.position);
	midground.Update(player.position);
	player.Update(time);

	if (keyLock && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		keyLock = false;
	}

	if (mouseLock && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		mouseLock = false;
	}

}

void Level::Draw(sf::Time time) {

	camera.Draw(window);

	background.Draw(window);
	midground.Draw(window);

	// Draw Tiles
	for (int r = 0; r < TileVector.size(); ++r) {
		for (int c = 0; c < TileVector[r].size(); ++c) {
			
			float leftTile = (c * TileWidth) + TileWidth;

			// Only draw air tiles and what's visible in the camera
			if (TileVector[r][c].tileType != "A" && (leftTile > camera.GetScreenPosition().x && c * TileWidth < (camera.GetScreenPosition().x + 1280))) {
				sf::Sprite tempSprite;
				tempSprite.setTextureRect(TileVector[r][c].GetRect());
				tempSprite.setTexture(TileVector[r][c].GetTexture());
				tempSprite.setPosition(c * TileWidth, r * TileHeight);

				window.draw(tempSprite);
			}

		}
	}

	player.Draw(window);

	if (showGameMenu) {
		menu.Draw(window);
	}

	//collision.Draw(window);

}
