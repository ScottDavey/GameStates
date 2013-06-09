#include "StateTwo.h"


StateTwo::StateTwo(sf::RenderWindow &window)
	: window(window)
{
	font.loadFromFile("Content/Font/GOTHIC.TTF");
	text.setFont(font);
	text.setCharacterSize(36);
	text.setPosition(75, 137);
	text.setColor(sf::Color::White);
	text.setString("State Two");
}


StateTwo::~StateTwo(void)
{
}

void StateTwo::Update(sf::Time time) {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		gameState = sm_MAIN;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		gameState = gm_MAIN;
	}

}

void StateTwo::Draw(sf::Time time)
{
	window.draw(text);
}
