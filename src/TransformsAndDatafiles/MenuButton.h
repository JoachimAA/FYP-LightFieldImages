#pragma once
#include <SFML\Graphics.hpp>
#include "Rectangle.h"

class MenuButton : public Rectangle
{
public:
	MenuButton();

	sf::Mouse m_mouse;
	
	void setUp(float xPos, float yPos, float xSize, float ySize);
	bool mouseHovering(sf::RenderWindow &window);
	bool mouseClicked(sf::RenderWindow &window);

	

};

