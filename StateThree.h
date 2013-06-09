#pragma once
#include <SFML/Graphics.hpp>
#include "BaseClass.h"

class StateThree : public BaseClass
{
private:
	sf::RenderWindow &window;

	sf::Font font;
	sf::Text text;
public:
	StateThree(sf::RenderWindow &window);
	~StateThree(void);
	StateThree & operator=(const StateThree&);

	void Update(sf::Time time);
	void Draw(sf::Time time);

};
