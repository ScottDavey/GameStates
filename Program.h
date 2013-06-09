#pragma once
#include <SFML/Graphics.hpp>
#include "BaseClass.h"
#include "State.h"
#include "StartMenu.h"
#include "StartMenu_Options.h"
#include "Level.h"
#include "StateTwo.h"
#include "StateThree.h"
#include <iostream>
#include <sstream>
#include <vector>

class Program
{
private:
	sf::RenderWindow window;
	sf::Event event;
	sf::Time elapsedTime;
	sf::Text text_FPS;
	sf::Font font_FPS;
	float fps;

	BaseClass *theClass;
	State activeState;

public:
	Program(void);
	~Program(void);

	bool Run();
};