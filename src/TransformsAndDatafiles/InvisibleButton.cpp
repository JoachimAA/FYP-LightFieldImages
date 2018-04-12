#include "InvisibleButton.h"

InvisibleButton::InvisibleButton(float xPos, float yPos, float xSize, float ySize)
{
	m_rectangle.setPosition(sf::Vector2f(xPos, yPos));
	m_rectangle.setSize(sf::Vector2f(xSize, ySize));
	m_xPosition = xPos;
	m_yPosition = yPos;
	m_xMax = xPos + xSize;
	m_yMax = yPos + ySize;
	m_rectangle.setFillColor(sf::Color::Transparent);
	m_rectangle.setOutlineThickness(1.0f);
	m_rectangle.setOutlineColor(sf::Color::Black);
}
//checks to see if mouse if over the button
bool InvisibleButton::mouseHovering(sf::RenderWindow & window)
{
	if (m_mouse.getPosition(window).x < m_xMax && m_mouse.getPosition(window).x > m_xPosition && m_mouse.getPosition(window).y < m_yMax && m_mouse.getPosition(window).y > m_yPosition)
	{
		return true;
	}
	else{
		return false;
	}

}

