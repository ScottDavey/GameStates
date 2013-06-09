#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>

class StartMenuBase
{
protected:
	sf::Texture background;
	sf::Sprite sprite;

	sf::Font gothic;
	sf::Font bebas;
	sf::Font harabara;

	sf::Text copyright;
	sf::Text release;

	sf::Texture TexutureSpriteSheet;

	sf::Sprite menuHeading;
	sf::IntRect menuHeadingRect;

	void setTextAttributes(sf::Text &text, sf::Font &font, sf::Color color, int size, float x, float y, std::string string);

public:
	StartMenuBase(void);
	~StartMenuBase(void);

};

