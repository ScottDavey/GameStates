#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class CollisionLayer
{
private:

public:
	CollisionLayer(void);
	~CollisionLayer(void);
	CollisionLayer & operator=(const CollisionLayer&);

	void Update(sf::Time time);
	void Draw(sf::RenderWindow &window);
};

