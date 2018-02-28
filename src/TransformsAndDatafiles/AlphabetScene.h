#pragma once
#include "GameScene.h"

class AlphabetScene : public GameScene
{
	void load(int level) override;
	void handleInput(sf::Event &ev) override;
	void render(sf::RenderWindow &window) override;
	int update(sf::RenderWindow &window, sf::Clock &gameClock) override;



};