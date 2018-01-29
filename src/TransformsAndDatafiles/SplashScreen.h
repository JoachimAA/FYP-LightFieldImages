#pragma once
#include "Scene.h"
#include "MenuButton.h"
#include "Background.h"
#include "SceneManager.h"

class SplashScreen : public Scene
{
public:
	void load();
	void render(sf::RenderWindow &window);
	bool update(sf::RenderWindow &window);

	MenuButton m_playButton;
	Background m_background;

private:

	 
};