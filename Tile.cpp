#include "Tile.h"

Tile::Tile(sf::Texture& image, sf::IntRect rect, int x, int y, std::string collision, std::string tileType) {
	this->texture = image;
	this->rect = rect;
	this->x = x;
	this->y = y;
	this->tileType = tileType;
	this->collision = collision;
}

Tile::Tile(int x, int y, std::string collision, std::string tileType) {
	this->x = x;
	this->y = y;
	this->tileType = tileType;
	this->collision = collision;
}

Tile::Tile(void)
{
}


Tile::~Tile(void)
{
}

int Tile::GetX() {
	return x;
}

int Tile::GetY() {
	return y;
}

std::string Tile::GetTileType() {
	return tileType;
}

std::string Tile::GetCollision() {
	return collision;
}

sf::Texture& Tile::GetTexture() {
	return texture;
}

sf::IntRect Tile::GetRect() {
	return rect;
}