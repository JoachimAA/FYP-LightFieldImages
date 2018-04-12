#pragma once
#include <SFML\Graphics.hpp>
#include "Rectangle.h"
#include "Text.h"

class Button : public Rectangle
{
public:

	Text* m_buttonText;  //text for the button 
	sf::Texture m_buttonTexture;     //texture for the button
	
	Button(float xPos, float yPos, float xSize, float ySize,std::string font, std::string buttonMessage, float textSize, sf::Color textColour);
	bool mouseHovering(sf::RenderWindow &window);

};

