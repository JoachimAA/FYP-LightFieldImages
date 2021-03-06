#include "MenuButton.h"
#include <iostream>


MenuButton::MenuButton()
{

}

void MenuButton::setUp(float xPos, float yPos, float xSize, float ySize)
{
	m_rectangle.setPosition(sf::Vector2f(xPos, yPos));
	m_rectangle.setSize(sf::Vector2f(xSize, ySize));
	xPosition = xPos;
	yPosition = yPos;
	xMax = xPos + xSize;
	yMax = yPos + ySize;
}

bool MenuButton::mouseHovering(sf::RenderWindow & window)
{
	if (m_mouse.getPosition(window).x < xMax && m_mouse.getPosition(window).x > xPosition && m_mouse.getPosition(window).y < yMax && m_mouse.getPosition(window).y > yPosition)
	{
		//	std::cout << "button hit\n";
			m_rectangle.setFillColor(sf::Color::Green);
			return true;
	}
	else
	{
		m_rectangle.setFillColor(sf::Color::White);
		return false;
	}
}

bool MenuButton::mouseClicked(sf::RenderWindow& window)
{
	if (m_mouse.isButtonPressed(m_mouse.Left))
	{
		return true;
	}
	else
	{
		return false;
	}
}
