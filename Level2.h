#pragma once
#include <SFML/Graphics.hpp>
#include "BaseClass.h"
#include "Player2.h"
#include <iostream>
#include <fstream>

class Level2 : public BaseClass
{
private:
	sf::RenderWindow &window;

	sf::Texture background;
	sf::Texture foreground;
	sf::Texture grid;

	sf::Sprite bgSprite;	
	sf::Sprite fgSprite;
	sf::Sprite gridSprite;

	std::vector<std::vector<float>> collisionMap;

	Player2 player;

	void InitializeCollision(const char *path);
public:
	Level2(sf::RenderWindow &window);
	~Level2(void);
	Level2 & operator=( const Level2&);

	void Update(sf::Time time);
	void Draw(sf::Time time);
};

