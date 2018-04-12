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
	m_xPosition = xPos;
	m_yPosition = yPos;
	m_xMax = xPos + m_buttonSprite.getTexture()->getSize().x * m_buttonSprite.getScale().x;
	m_yMax = yPos + m_buttonSprite.getTexture()->getSize().y * m_buttonSprite.getScale().y;

}

//check if mouse if hovering over
bool TexturedButton::mouseHovering(sf::RenderWindow & window)
{
	if (m_mouse.getPosition(window).x < m_xMax && m_mouse.getPosition(window).x > m_xPosition && m_mouse.getPosition(window).y < m_yMax && m_mouse.getPosition(window).y > m_yPosition)
	{
		m_buttonSprite.setColor(sf::Color(255,255,255,150));
		return true;
	}
	else
	{
		m_buttonSprite.setColor(sf::Color::White);
		return false;
	}
}