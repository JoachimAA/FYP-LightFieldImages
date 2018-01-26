#pragma once
#include "Scene.h"
#include "MenuButton.h"
#include "Background.h"

class SplashScreen : public Scene
{
public:
	void load(float sizeX, float sizeY);
	void render(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);

	MenuButton m_playButton;
	Background m_background;

private:

	
};