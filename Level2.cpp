#include "Level2.h"


Level2::Level2(sf::RenderWindow &window)
	: window(window)
{

	if (!background.loadFromFile("Content/Images/VectorBased/Background.png") || 
		!foreground.loadFromFile("Content/Images/VectorBased/Foreground.png") ||
		!grid.loadFromFile("Content/Images/VectorBased/grid.png")) {
		std::cout << "No Background or foreground" << std::endl;
	}
	bgSprite.setTexture(background);
	bgSprite.setPosition(0.f, 0.f);
	fgSprite.setTexture(foreground);
	fgSprite.setPosition(0.f, 0.f);
	gridSprite.setTexture(grid);
	gridSprite.setPosition(0.f, 0.f);

	InitializeCollision("Content/Levels/VectorBased/1.txt");

}


Level2::~Level2(void)
{
}

void Level2::InitializeCollision(const char *path) {
	
	std::ifstream openfile(path);
	std::vector<float> tempVector;
	float x, y;

	// Store all numbers in the file to a 2D vector (collisionMap)
	if (openfile.is_open()) {

		while (openfile >> x >> y) {
			tempVector.push_back(x);
			tempVector.push_back(y);
			collisionMap.push_back(tempVector);
			tempVector.clear();
		}

		openfile.close();

	} else {
		std::cout << "Unable to open file" << std::endl;
	}

	player.Initialize(collisionMap);

}

void Level2::Update(sf::Time time) {
	player.Update(time);
}

void Level2::Draw(sf::Time time) {

	/*sf::VertexArray line1(sf::LinesStrip, 2);
	sf::VertexArray line2(sf::LinesStrip, 2);
	sf::VertexArray line3(sf::LinesStrip, 2);
	sf::VertexArray line4(sf::LinesStrip, 2);
	sf::VertexArray line5(sf::LinesStrip, 2);
	sf::VertexArray line6(sf::LinesStrip, 2);
	sf::VertexArray line7(sf::LinesStrip, 2);
	sf::VertexArray line8(sf::LinesStrip, 2);
	sf::VertexArray line9(sf::LinesStrip, 2);
	sf::VertexArray line10(sf::LinesStrip, 2);
	sf::VertexArray line11(sf::LinesStrip, 2);
	sf::VertexArray line12(sf::LinesStrip, 2);
	sf::VertexArray line13(sf::LinesStrip, 2);

	line1[0].position = sf::Vector2f(0.f, 455.f);
	line1[1].position = sf::Vector2f(85.f, 485.f);

	line2[0].position = sf::Vector2f(85.f, 485.f);
	line2[1].position = sf::Vector2f(125.f, 488.f);

	line3[0].position = sf::Vector2f(125.f, 488.f);
	line3[1].position = sf::Vector2f(255.f, 483.f);

	line4[0].position = sf::Vector2f(255.f, 483.f);
	line4[1].position = sf::Vector2f(332.f, 477.f);

	line5[0].position = sf::Vector2f(332.f, 477.f);
	line5[1].position = sf::Vector2f(373.f, 464.f);

	line6[0].position = sf::Vector2f(373.f, 464.f);
	line6[1].position = sf::Vector2f(488.f, 409.f);

	line7[0].position = sf::Vector2f(488.f, 409.f);
	line7[1].position = sf::Vector2f(568.f, 367.f);

	line8[0].position = sf::Vector2f(568.f, 367.f);
	line8[1].position = sf::Vector2f(611.f, 348.f);

	line9[0].position = sf::Vector2f(611.f, 348.f);
	line9[1].position = sf::Vector2f(673.f, 329.f);

	line10[0].position = sf::Vector2f(673.f, 329.f);
	line10[1].position = sf::Vector2f(773.f, 317.f);

	line11[0].position = sf::Vector2f(773.f, 317.f);
	line11[1].position = sf::Vector2f(930.f, 302.f);

	line12[0].position = sf::Vector2f(930.f, 302.f);
	line12[1].position = sf::Vector2f(1042.f, 309.f);

	line13[0].position = sf::Vector2f(1042.f, 309.f);
	line13[1].position = sf::Vector2f(1080.f, 305.f);*/

	window.draw(bgSprite);
	/*window.draw(line1);
	window.draw(line2);
	window.draw(line3);
	window.draw(line4);
	window.draw(line5);
	window.draw(line6);
	window.draw(line7);
	window.draw(line8);
	window.draw(line9);
	window.draw(line10);
	window.draw(line11);
	window.draw(line12);
	window.draw(line13);*/
	player.Draw(window);
	window.draw(fgSprite);
	window.draw(gridSprite);
}
