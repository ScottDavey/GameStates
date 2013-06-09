#include "StateThree.h"


StateThree::StateThree(sf::RenderWindow &window)
	: window(window)
{
	font.loadFromFile("Content/Font/GOTHIC.TTF");
	text.setFont(font);
	text.setCharacterSize(36);
	text.setPosition(75, 137);
	text.setColor(sf::Color::White);
	text.setString("State Three");
}


StateThree::~StateThree(void)
{
}

void StateThree::Update(sf::Time time) {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		gameState = sm_MAIN;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		gameState = GAME;
	}

}

void StateThree::Draw(sf::Time time)
{
	window.draw(text);
}

