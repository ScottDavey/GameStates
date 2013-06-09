#include "Program.h"

State BaseClass::gameState = sm_MAIN;

Program::Program(void)
	: window(sf::VideoMode(1280, 720), "Finite State Machine"),
	activeState(sm_MAIN)
{

	window.setFramerateLimit(60);

	font_FPS.loadFromFile("Content/Font/GOTHIC.TTF");

	// FPS Text
	text_FPS.setFont(font_FPS);
	text_FPS.setCharacterSize(12);
	text_FPS.setColor(sf::Color(85, 85, 85));
	text_FPS.setPosition(605, 700);

	fps = 0.0f;

	theClass = new StartMenu(window);
	theClass->setState(sm_MAIN);
}


Program::~Program(void)
{
	delete theClass;
}

bool Program::Run () {
	
	sf::Clock GameTime;

	while (window.isOpen()) {
		
		elapsedTime = GameTime.restart();

		if (activeState != theClass->getState()) {
			activeState = theClass->getState();

			if (theClass)
				delete theClass;

			switch (activeState) {
				case sm_MAIN:
					theClass = new StartMenu(window);
					break;
				case sm_OPTIONS:
					theClass = new StartMenu_Options(window);
					break;
				case GAME:
					theClass = new Level(window);
					break;
				case gm_MAIN:
					theClass = new StateThree(window);
					break;
				default:
					theClass = new StartMenu(window);
					break;
			}

		}

		// Poll Events
		while (window.pollEvent(event)) {			
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// FPS
		int FPS = static_cast<int> (1.0f / elapsedTime.asSeconds());
		fps += elapsedTime.asSeconds();
		if (fps >= 0.2f) {
			std::ostringstream Converter;
			Converter << "FPS " << FPS;
			text_FPS.setString(Converter.str());

			fps = 0.0f;
		}

		window.clear(sf::Color(34, 34, 34, 100));
		theClass->Update(elapsedTime);
		theClass->Draw(elapsedTime);
		window.draw(text_FPS);
		window.display();

	}

	return true;

}
