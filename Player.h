#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f position;

public:
	Player(void);
	~Player(void);
	Player & operator=(const Player&);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);

	void Update(sf::Time time);
	void Draw(sf::RenderWindow &window);
};

