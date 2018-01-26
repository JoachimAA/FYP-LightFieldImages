#include "Background.h"

void Background::setUp(float xPos, float yPos, float xSize, float ySize, std::string texture)
{
	m_rectangle.setPosition(sf::Vector2f(xPos, yPos));
	m_rectangle.setSize(sf::Vector2f(xSize, ySize));
	xPosition = xPos;
	xPosition = yPos;
	xMax = xPos + xSize;
	yMax = yPos + ySize;
	loadTexture(texture);
	m_rectangle.setTexture(&m_texture);

}



