#include "Text.h"

Text::Text(std::string font, std::string message, float size, sf::Color colour, float xPos, float yPos)
{
	m_font.loadFromFile(font);
	m_text.setString(message);
	m_text.setFont(m_font);
	m_text.setCharacterSize(size);
	m_text.setColor(colour);
	m_text.setPosition(sf::Vector2f(xPos, yPos));
}

void Text::render(sf::RenderWindow & window)
{
	window.draw(m_text);

}
