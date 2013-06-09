#include "StartMenuBase.h"


StartMenuBase::StartMenuBase(void)
{

	// Background
	if (!background.loadFromFile("Content/Images/StartMenuBackground.png"))
		std::cout << "Background could not load" << std::endl;
	sprite.setTexture(background);
	sprite.setPosition(0, 0);

	if (!TexutureSpriteSheet.loadFromFile("Content/Images/StartMenu_SpriteSheet.png")) {
		std::cout << "Could not load spritesheet" << std::endl;
	}

	gothic.loadFromFile("Content/Font/GOTHIC.TTF");
	bebas.loadFromFile("Content/Font/BebasNeue.otf");
	harabara.loadFromFile("Content/Font/Harabara.ttf");

	setTextAttributes(copyright, gothic, sf::Color(85, 85, 85), 12, 5.f, 700.f, "Copyright 2013, 0026sd");
	setTextAttributes(release, gothic, sf::Color(85, 85, 85), 12, 1148.f, 700.f, "Alpha Release: v1.0.0");

	menuHeadingRect = sf::IntRect(0, 0, 380, 54);

	menuHeading.setTexture(TexutureSpriteSheet);
	menuHeading.setTextureRect(menuHeadingRect);
	menuHeading.setPosition(240.f, 160.f);

}


StartMenuBase::~StartMenuBase(void)
{
}

void StartMenuBase::setTextAttributes(sf::Text &text, sf::Font &font, sf::Color color, int size, float x, float y, std::string string) {
	text.setFont(font);
	text.setColor(color);
	text.setCharacterSize(size);
	text.setPosition(x, y);
	text.setString(string);
}