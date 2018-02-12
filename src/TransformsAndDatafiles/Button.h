#pragma once
#include <SFML\Graphics.hpp>
#include "Rectangle.h"
#include "Text.h"

class Button : public Rectangle
{
public:

	sf::Mouse m_mouse;
	Text* m_buttonText;
	
	Button(float xPos, float yPos, float xSize, float ySize,std::string font, std::string buttonMessage, float textSize, sf::Color textColour);
	bool mouseHovering(sf::RenderWindow &window);
	bool mouseClicked(sf::RenderWindow &window);

	

};

