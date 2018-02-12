#pragma once

#include <SFML\Graphics.hpp>

class Text
{
public:

	Text(std::string font ,std::string message ,float textSize , sf::Color colour , float xPos , float yPos );
	void render(sf::RenderWindow &window);

	sf::Font m_font;
	sf::Text m_text;

	std::vector<std::string> vecOfFonts;
};