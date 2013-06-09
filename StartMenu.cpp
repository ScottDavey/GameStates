#include "StartMenu.h"


StartMenu::StartMenu(sf::RenderWindow &window)
	: window(window)
{

	setTextAttributes(menuEntryStart, bebas, sf::Color(255, 255, 255), 36, 250.f, 250.f, "Start");
	setTextAttributes(menuEntryOptions, bebas, sf::Color(255, 255, 255), 36, 250.f, 325.f, "Options");
	setTextAttributes(menuEntryQuit, bebas, sf::Color(255, 255, 255), 36, 250.f, 400.f, "Quit");

	menuEntryStartRect = sf::IntRect(250, 250, 80, 45);
	menuEntryOptionsRect = sf::IntRect(250, 325, 110, 45);
	menuEntryQuitRect = sf::IntRect(250, 400, 70, 45);

	mouseLock = true;

}


StartMenu::~StartMenu(void)
{
}

void StartMenu::Update(sf::Time time) {

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	if (menuEntryStartRect.contains(mousePos) && !mouseLock) {
		menuEntryStart.setColor(sf::Color(0, 255, 128));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameState = GAME;
		}
		mouseLock = true;
	} else if (menuEntryOptionsRect.contains(mousePos) && !mouseLock) {
		menuEntryOptions.setColor(sf::Color(0, 255, 128));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameState = sm_OPTIONS;
		}
		mouseLock = true;
	} else if (menuEntryQuitRect.contains(mousePos) && !mouseLock) {
		menuEntryQuit.setColor(sf::Color(0, 255, 128));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			window.close();
		}
		mouseLock = true;
	} else {
		menuEntryStart.setColor(sf::Color(255, 255, 255));
		menuEntryOptions.setColor(sf::Color(255, 255, 255));
		menuEntryQuit.setColor(sf::Color(255, 255, 255));
	}

	if (mouseLock && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		mouseLock = false;
	}

}

void StartMenu::Draw(sf::Time time) {
	window.draw(sprite);
	window.draw(copyright);
	window.draw(release);
	window.draw(menuHeading);
	window.draw(menuEntryStart);
	window.draw(menuEntryOptions);
	window.draw(menuEntryQuit);
}