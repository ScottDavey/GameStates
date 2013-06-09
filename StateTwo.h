#pragma once
#include <SFML/Graphics.hpp>
#include "BaseClass.h"

class StateTwo : public BaseClass
{
private:

	sf::RenderWindow &window;

	sf::Font font;
	sf::Text text;
public:
	StateTwo(sf::RenderWindow &window);
	~StateTwo(void);
	StateTwo & operator=(const StateTwo&);

	void Update(sf::Time time);
	void Draw(sf::Time time);

};

