#pragma once

#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Rectangle : public GameObject
{
public:

	sf::RectangleShape m_rectangle;
	sf::Sprite m_buttonSprite;  //sprite for button
	sf::Texture m_texture;  //texture for button
	sf::Mouse m_mouse;

	float m_xMax;
	float m_yMax;

	float getXMax();
	float getYMax();

	void render(sf::RenderWindow &window);
	void renderSprite(sf::RenderWindow & window);
	void loadTexture(std::string texture);
	void rotateSprite(float angle);


	bool mouseClicked(sf::RenderWindow &window);
};