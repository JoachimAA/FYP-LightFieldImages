#include "Button.h"
#include <iostream>

Button::Button(float xPos, float yPos, float xSize, float ySize,std::string font, std::string buttonMessage, float textSize , sf::Color textColour)
{
	m_rectangle.setPosition(sf::Vector2f(xPos, yPos));
	m_rectangle.setSize(sf::Vector2f(xSize, ySize));
	m_xPosition = xPos;
	m_yPosition = yPos;
	m_xMax = xPos + xSize;
	m_yMax = yPos + ySize;
	m_buttonText = new Text(font, buttonMessage, textSize, textColour, xPos + 15.0f,yPos + ySize / 10.0f);
	
}

//check is mouse if hovering over the button
bool Button::mouseHovering(sf::RenderWindow & window)
{
	if (m_mouse.getPosition(window).x < m_xMax && m_mouse.getPosition(window).x > m_xPosition && m_mouse.getPosition(window).y < m_yMax && m_mouse.getPosition(window).y > m_yPosition)
	{
		//if it hovering over turn green
			m_rectangle.setFillColor(sf::Color::Green);
			return true;
	}
	else
	{
		//if not set to white
		m_rectangle.setFillColor(sf::Color::White);
		return false;
	}
}
