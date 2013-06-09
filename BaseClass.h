#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"

class BaseClass
{
protected:
	static State gameState;
public:
	BaseClass() {}
	virtual ~BaseClass() {}

	static void setState(State state) { gameState = state; }
	static State getState() { return gameState; }

	virtual void Update(sf::Time time) = 0;
	virtual void Draw(sf::Time time) = 0;

};
