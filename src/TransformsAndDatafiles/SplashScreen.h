#pragma once
#include "Scene.h"
#include "MenuButton.h"

class SplashScreen : public Scene
{
public:
	void load();
	void render(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);

	MenuButton * m_playButton;

private:

	
};