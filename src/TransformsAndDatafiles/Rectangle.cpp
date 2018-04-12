#include "Rectangle.h"
#include <iostream>

float Rectangle::getXMax()
{
	return m_xMax;
}

float Rectangle::getYMax()
{
	return m_yMax;
}

void Rectangle::render(sf::RenderWindow & window)
{
	window.draw(m_rectangle);
}

void Rectangle::renderSprite(sf::RenderWindow & window)
{
	window.draw(m_buttonSprite);
}

//load a texture
void Rectangle::loadTexture(std::string texture)
{
	if (!m_texture.loadFromFile(texture))
	{
		std::cout << " cant load texture\n ";
	}
}

//check for mouse click
bool Rectangle::mouseClicked(sf::RenderWindow & window)
{
	if (m_mouse.isButtonPressed(m_mouse.Left))  //if pressed by left mouse
	{
		return true;
	}
	else
	{
		return false;
	}
}
//rotates sprite
void Rectangle::rotateSprite(float angle)
{
	m_buttonSprite.rotate(angle);  //rotate by angle
	m_buttonSprite.move(sf::Vector2f(m_xMax - m_xPosition, m_yMax - m_yPosition));  //moves so that it doesnt move when rotating
}