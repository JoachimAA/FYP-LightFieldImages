#include "TexturedButton.h"
#include <iostream>

TexturedButton::TexturedButton(float xPos, float yPos, float xScale, float yScale, std::string texture)
{
	if (!m_buttonTexture.loadFromFile(texture))
	{
		std::cout << "cant load texture" << std::endl;
	}
	
	m_buttonSprite.setPosition(sf::Vector2f(xPos, yPos));
	m_buttonSprite.setScale(sf::Vector2f(xScale, yScale));
	m_buttonSprite.setTexture(m_buttonTexture,true);
	xPosition = xPos;
	yPosition = yPos;
	xMax = xPos + m_buttonSprite.getTexture()->getSize().x * m_buttonSprite.getScale().x;
	yMax = yPos + m_buttonSprite.getTexture()->getSize().y * m_buttonSprite.getScale().y;

}

bool TexturedButton::mouseHovering(sf::RenderWindow & window)
{
	if (m_mouse.getPosition(window).x < xMax && m_mouse.getPosition(window).x > xPosition && m_mouse.getPosition(window).y < yMax && m_mouse.getPosition(window).y > yPosition)
	{
		//	std::cout << "button hit\n";
		m_buttonSprite.setColor(sf::Color(255,255,255,150));
		return true;
	}
	else
	{
		m_buttonSprite.setColor(sf::Color::White);
		return false;
	}
}