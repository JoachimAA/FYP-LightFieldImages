#pragma once
#include "Rectangle.h"

class InvisibleButton : public Rectangle
{
public:
	sf::Mouse m_mouse;
	InvisibleButton(float xPos, float yPos, float xSize, float ySize);
	bool mouseHovering(sf::RenderWindow &window);
	bool mouseClicked(sf::RenderWindow &window);
};