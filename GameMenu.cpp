#include "GameMenu.h"


GameMenu::GameMenu(void)
{
	if (!texture.loadFromFile("Content/Images/GameMenu_Background.png")) {
		std::cout << "Couldn't load GameMenu BG" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(390.f, 210.f);

	gothic.loadFromFile("Content/Font/GOTHIC.TTF");
	bebas.loadFromFile("Content/Font/BebasNeue.otf");
	
	setTextAttributes(heading, gothic, sf::Color(255, 255, 255), 36, 410.f, 230.f, "Game Menu");
	setTextAttributes(menuEntryQuit, bebas, sf::Color(200, 200, 200), 30, 420.f, 300.f, "Quit");
	setTextAttributes(menuEntryBack, bebas, sf::Color(200, 200, 200), 30, 420.f, 340.f, "Back (Esc)");
	setTextAttributes(menuEntryMenu, bebas, sf::Color(200, 200, 200), 30, 420.f, 380.f, "Main Menu");

	quitRect = sf::IntRect(420.f, 300.f, 40.f, 30.f);
	backRect = sf::IntRect(420.f, 340.f, 100.f, 30.f);
	menuRect = sf::IntRect(420.f, 380.f, 100.f, 30.f);

	mouseLock = true;

}


GameMenu::~GameMenu(void)
{
}

void GameMenu::setTextAttributes(sf::Text &text, sf::Font &font, sf::Color color, int size, float x, float y, std::string string) {
	text.setFont(font);
	text.setColor(color);
	text.setCharacterSize(size);
	text.setPosition(x, y);
	text.setString(string);
}

void GameMenu::setQuitColor(sf::Color color) {
	menuEntryQuit.setColor(color);
}

void GameMenu::setBackColor(sf::Color color) {
	menuEntryBack.setColor(color);
}

void GameMenu::setMenuColor(sf::Color color) {
	menuEntryMenu.setColor(color);
}

sf::IntRect GameMenu::getQuitRect() {
	return quitRect;
}

sf::IntRect GameMenu::getBackRect() {
	return backRect;
}

sf::IntRect GameMenu::getMenuRect() {
	return menuRect;
}

void GameMenu::Update(sf::RenderWindow &window) {
}

void GameMenu::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
	window.draw(heading);
	window.draw(menuEntryQuit);
	window.draw(menuEntryBack);
	window.draw(menuEntryMenu);
}