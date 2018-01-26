#pragma once

#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Rectangle : public GameObject
{
public:

	sf::RectangleShape m_rectangle;
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	float xMax;
	float yMax;

	float getXMax();
	float getYMax();

	void render(sf::RenderWindow &window);
	void loadTexture(std::string texture);
};