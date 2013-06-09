#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ImageManager
{
private:
	std::vector<sf::Texture> imageList;
	std::map<int, int> imageIDs;

public:
	ImageManager(void);
	~ImageManager(void);

	void AddImage(std::string &path, int id);
	sf::Texture& GetImage(int id);
	void ClearImage();
};

