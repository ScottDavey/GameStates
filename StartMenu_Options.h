#pragma once
#include <SFML/Graphics.hpp>
#include "BaseClass.h"
#include "StartMenuBase.h"
#include <iostream>
#include <sstream>

class StartMenu_Options : public BaseClass, StartMenuBase
{
private:
	sf::RenderWindow &window;

	sf::Text menuEntryBack;
	sf::Text menuEntryVideo;
	sf::Text menuEntryCredits;

	sf::IntRect menuEntryBackRect;
	sf::IntRect menuEntryVideoRect;
	sf::IntRect menuEntryCreditsRect;

	std::ostringstream videoSettingsString;
	sf::Text videoSettings;

	std::string verticalSync;
	bool showVideo;
	
	std::string creditText;
	sf::Text credits;

	bool showCredits;
	float creditAlpha;

	bool mouseLock;

public:
	StartMenu_Options(sf::RenderWindow &window);
	~StartMenu_Options(void);
	StartMenu_Options & operator=(const StartMenu_Options&);

	void Update(sf::Time elapsedTime);
	void Draw(sf::Time elapsedTime);

};

