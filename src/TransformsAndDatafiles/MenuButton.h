#pragma once
#include <SFML\Graphics.hpp>

class MenuButton
{
public:
	MenuButton();


	sf::RectangleShape m_button;
	sf::Mouse m_mouse;

	//top left
	float xPosition;
	float yPosition;
	
	
	float xMax;
	float yMax;
	
	void setUp(float xPos, float yPos, float xSize, float ySize);
	void mouseClicked(sf::RenderWindow &window);
	float getXMax();
	float getYMax();
	float getXMin();
	float getYMin();

	void render(sf::RenderWindow &window);

};

