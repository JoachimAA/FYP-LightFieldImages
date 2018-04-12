#include "Background.h"

Background::Background(float xPos, float yPos, float xSize, float ySize, std::string texture)
{
	m_rectangle.setPosition(sf::Vector2f(xPos, yPos));
	m_rectangle.setSize(sf::Vector2f(xSize, ySize));
	m_xPosition = xPos;
	m_yPosition = yPos; 
	m_xMax = xPos + xSize;      //setting all variables
	m_yMax = yPos + ySize;
	loadTexture(texture);
	m_rectangle.setTexture(&m_texture);

}



