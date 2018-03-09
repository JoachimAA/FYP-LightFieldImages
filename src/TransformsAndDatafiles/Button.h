#pragma once
#include <SFML\Graphics.hpp>
#include "Rectangle.h"
#include "Text.h"

class Button : public Rectangle
{
public:

	Text* m_buttonText;
	sf::Texture m_buttonTexture;
	
	Button(float xPos, float yPos, float xSize, float ySize,std::string font, std::string buttonMessage, float textSize, sf::Color textColour, std::string texture);
	bool mouseHovering(sf::RenderWindow &window);

};

