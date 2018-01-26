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

void Rectangle::loadTexture(std::string texture)
{
	if (!m_texture.loadFromFile(texture))
	{
		std::cout << " cant load texture\n ";
	}
}
