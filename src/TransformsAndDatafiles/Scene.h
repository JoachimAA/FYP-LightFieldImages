#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "SoundManager.h"
#include "Background.h"
#include "Button.h"
#include "InvisibleButton.h"
#include "Text.h"

class Scene
{
public : 
	SoundManager sceneSoundManager;


	virtual void load(int level) = 0;
	virtual void render(sf::RenderWindow &window) = 0;
	virtual int update(sf::RenderWindow &window, sf::Clock &gameClock) = 0;
	virtual void handleInput(sf::Event &ev) = 0;

};