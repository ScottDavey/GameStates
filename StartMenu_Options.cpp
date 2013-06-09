#include "StartMenu_Options.h"


StartMenu_Options::StartMenu_Options(sf::RenderWindow &window)
	: window(window)
{

	setTextAttributes(menuEntryBack, bebas, sf::Color(255, 255, 255), 36, 250.f, 250.f, "Back");
	setTextAttributes(menuEntryVideo, bebas, sf::Color(255, 255, 255), 36, 250.f, 325.f, "Video");
	setTextAttributes(menuEntryCredits, bebas, sf::Color(255, 255, 255), 36, 250.f, 400.f, "Credits");

	menuEntryBackRect = sf::IntRect(250, 250, 80, 45);
	menuEntryVideoRect = sf::IntRect(250, 325, 80, 45);
	menuEntryCreditsRect = sf::IntRect(250, 400, 110, 45);

	verticalSync = "false";
	videoSettingsString << "Vertical Sync:\t\t" << verticalSync << "\n";
	setTextAttributes(videoSettings, gothic, sf::Color(170, 170, 170), 20, 400.f, 260.f, videoSettingsString.str());

	showVideo = false;

	creditText = "GameStates:\n\nGameStates was created by 0026sd\nand was meant for learning purposes.\n\nThe Graphics and fonts in this program\nare being used for personal development only.";
	setTextAttributes(credits, gothic, sf::Color(170, 170, 170, 0), 20, 400.f, 260.f, creditText);

	showCredits = false;
	creditAlpha = 0;

	mouseLock = true;

}


StartMenu_Options::~StartMenu_Options(void)
{
}

void StartMenu_Options::Update(sf::Time elapsedTime) {

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	if (menuEntryBackRect.contains(mousePos) && !mouseLock) {
		// BACK BUTTON
		menuEntryBack.setColor(sf::Color(0, 255, 128));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameState = sm_MAIN;
		}
		mouseLock = true;
	} else if (menuEntryVideoRect.contains(mousePos) && !mouseLock) {
		// VIDEO BUTTON
		menuEntryVideo.setColor(sf::Color(0, 255, 128));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			showVideo = true;
			showCredits = false;
		}
		mouseLock = true;
	} else if (menuEntryCreditsRect.contains(mousePos) && !mouseLock) {
		// CREDITS BUTTON
		menuEntryCredits.setColor(sf::Color(0, 255, 128));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			showCredits = true;
			showVideo = false;
		}
		mouseLock = true;
	} else {
		menuEntryBack.setColor(sf::Color(255, 255, 255));
		menuEntryVideo.setColor(sf::Color(255, 255, 255));
		menuEntryCredits.setColor(sf::Color(255, 255, 255));
	}

	if (mouseLock && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		mouseLock = false;
	}

	// Credit animation
	if (showCredits && creditAlpha < 255) {
		credits.setColor(sf::Color(170, 170, 170, creditAlpha));
		if (creditAlpha < 255) {
			creditAlpha += 1 * 2500 * elapsedTime.asSeconds();
		} else {
			creditAlpha = 255;
		}
	}

}

void StartMenu_Options::Draw(sf::Time elapsedime) {
	window.draw(sprite);
	window.draw(copyright);
	window.draw(release);
	window.draw(menuHeading);
	window.draw(menuEntryBack);
	window.draw(menuEntryVideo);
	window.draw(menuEntryCredits);
	if (showCredits) {
		window.draw(credits);
	} else if (showVideo) {
		window.draw(videoSettings);
	}
}
