#pragma once
#include "GameScene.h"

class PracticeScene : public GameScene
{
	void load(int level) override;
	void handleInput(sf::Event &ev) override;
	void render(sf::RenderWindow &window) override;
	int update(sf::RenderWindow &window, sf::Clock &gameClock) override;

	vector<string> vecOfHints;
	Text * m_hints;

	bool displayHint;
};