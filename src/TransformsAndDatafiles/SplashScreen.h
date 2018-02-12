#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Text.h"

class SplashScreen : public Scene
{
public:
	void load() override;
	void render(sf::RenderWindow &window) override;
	bool update(sf::RenderWindow &window) override;

	Button* m_playButton;
	Background* m_background;
	Text * m_play;


private:

	 
};