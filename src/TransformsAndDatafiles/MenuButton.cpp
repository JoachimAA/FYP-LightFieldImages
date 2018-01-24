#include "MenuButton.h"
#include <iostream>


MenuButton::MenuButton()
{

}

void MenuButton::setUp(float xPos, float yPos, float xSize, float ySize)
{
	m_button.setPosition(sf::Vector2f(xPos, yPos));
	m_button.setSize(sf::Vector2f(xSize, ySize));
	xPosition = xPos;
	yPosition = yPos;
	xMax = xPos + xSize;
	yMax = yPos + ySize;
}

void MenuButton::mouseClicked(sf::RenderWindow & window)
{
	if (m_mouse.getPosition(window).x < xMax && m_mouse.getPosition(window).x > xPosition && m_mouse.getPosition(window).y < yMax && m_mouse.getPosition(window).y > yPosition)
	{
		//	std::cout << "button hit\n";
			m_button.setFillColor(sf::Color::Green);
	}
	else
	{
		m_button.setFillColor(sf::Color::White);
	}
}

float MenuButton::getXMax()
{
	return xMax;
}
float MenuButton::getYMax()
{
	return yMax;
}
float MenuButton::getXMin()
{
	return xPosition;
}
float MenuButton::getYMin()
{
	return yPosition;
}

void MenuButton::render(sf::RenderWindow &window)
{
	window.draw(m_button);
}
