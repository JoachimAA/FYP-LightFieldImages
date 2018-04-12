#pragma once
#include "GameScene.h"

class PracticeScene : public GameScene
{
	void load(int level) override;
	void handleInput(sf::Event &ev) override;
	void render(sf::RenderWindow &window) override;
	int update(sf::RenderWindow &window, sf::Clock &gameClock) override;

	vector<string> m_vecOfHints;  //stores hints
	Text * m_hints;   //text for the hint to come up on screen

	bool m_displayHint;  //display hint
};