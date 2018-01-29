#pragma once
#include "Scene.h"
#include "Background.h"


class GameScene : public Scene
{
public:

	Background m_background;

	std::vector<Background> vecOfBackgrounds;

	void load();
	void render(sf::RenderWindow &window);
	bool update(sf::RenderWindow &window);

	sf::Mouse m_mouse;
};