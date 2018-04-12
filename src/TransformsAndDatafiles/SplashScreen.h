#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Text.h"

class SplashScreen : public Scene
{
public:
	void load(int level) override;
	void render(sf::RenderWindow &window) override;
	int update(sf::RenderWindow &window, sf::Clock &gameClock) override;
	void handleInput(sf::Event &ev) override;


	Button* m_spellingButton;
	Button* m_alphabetButton;   //buttons for splash screen 
	Background* m_background;  //background



private:

	 
};