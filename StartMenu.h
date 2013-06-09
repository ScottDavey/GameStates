#pragma once
#include <SFML/Graphics.hpp>
#include "BaseClass.h"
#include "StartMenuBase.h"
#include <iostream>

class StartMenu : public BaseClass, StartMenuBase
{
private:

	sf::RenderWindow &window;

	sf::Text menuEntryStart;
	sf::Text menuEntryOptions;
	sf::Text menuEntryQuit;

	sf::IntRect menuEntryStartRect;
	sf::IntRect menuEntryOptionsRect;
	sf::IntRect menuEntryQuitRect;

	bool mouseLock;

public:
	StartMenu(sf::RenderWindow &window);
	~StartMenu(void);
	StartMenu & operator=( const StartMenu&);

	void Update(sf::Time time);
	void Draw(sf::Time time);

};

