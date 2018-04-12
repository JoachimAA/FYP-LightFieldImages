#pragma once

#include "Rectangle.h"

class TexturedButton : public Rectangle
{
public:
	TexturedButton(float xPos, float yPos, float xScale, float yScale, std::string texture);
	bool mouseHovering(sf::RenderWindow &window);
	sf::Texture m_buttonTexture;


private:


};