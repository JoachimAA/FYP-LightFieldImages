#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "SoundManager.h"
#include "Background.h"
#include "Button.h"

class Scene
{
public : 
	SoundManager sceneSoundManager;


	virtual void load() = 0;
	virtual void render(sf::RenderWindow &window) = 0;
	virtual bool update(sf::RenderWindow &window) = 0;
	//m_background
};