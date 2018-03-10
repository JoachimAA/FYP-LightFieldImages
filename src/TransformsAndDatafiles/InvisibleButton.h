#pragma once
#include "Rectangle.h"

class InvisibleButton : public Rectangle
{
public:
	
	InvisibleButton(float xPos, float yPos, float xSize, float ySize);
	bool mouseHovering(sf::RenderWindow &window);
	
	//getFillColour()

};