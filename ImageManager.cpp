#include "ImageManager.h"


ImageManager::ImageManager(void)
{
}


ImageManager::~ImageManager(void)
{
}

void ImageManager::AddImage(std::string &path, int id) {
	sf::Texture image;
	if (image.loadFromFile(path)) {
		imageList.push_back(image);
		imageIDs[id] = imageList.size() - 1;
	}
}	

sf::Texture& ImageManager::GetImage(int id) {
	return imageList[imageIDs][id];
}

void ImageManager::ClearImage() {
	imageList.clear();
}