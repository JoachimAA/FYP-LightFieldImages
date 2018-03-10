#include "Rectangle.h"
#include <iostream>

float Rectangle::getXMax()
{
	return xMax;
}

float Rectangle::getYMax()
{
	return yMax;
}

void Rectangle::render(sf::RenderWindow & window)
{
	window.draw(m_rectangle);
}

void Rectangle::renderSprite(sf::RenderWindow & window)
{
	window.draw(m_buttonSprite);
}

void Rectangle::loadTexture(std::string texture)
{
	if (!m_texture.loadFromFile(texture))
	{
		std::cout << " cant load texture\n ";
	}
}

bool Rectangle::mouseClicked(sf::RenderWindow & window)
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

void Rectangle::rotateSprite(float angle)
{
	m_buttonSprite.rotate(angle);
	m_buttonSprite.move(sf::Vector2f(xMax - xPosition, yMax - yPosition));
}