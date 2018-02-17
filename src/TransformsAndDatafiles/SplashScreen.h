#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Text.h"

class SplashScreen : public Scene
{
public:
	void load(int level) override;
	void render(sf::RenderWindow &window) override;
	int update(sf::RenderWindow &window) override;

	Button* m_spellingButton;
	Button* m_alphabetButton;
	Background* m_background;
	Text * m_play;


private:

	 
};