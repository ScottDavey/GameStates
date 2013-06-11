#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameMenu
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Font gothic;
	sf::Font bebas;

	sf::Text heading;
	sf::Text menuEntryQuit;
	sf::Text menuEntryBack;

	sf::IntRect quitRect;
	sf::IntRect backRect;

	void setTextAttributes(sf::Text &text, sf::Font &font, sf::Color color, int size, float x, float y, std::string string);

	bool mouseLock;

public:
	GameMenu(void);
	~GameMenu(void);
	GameMenu & operator=(const GameMenu&);

	void setQuitColor(sf::Color color);
	void setBackColor(sf::Color color);
	sf::IntRect getQuitRect();
	sf::IntRect getBackRect();

	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);

};

