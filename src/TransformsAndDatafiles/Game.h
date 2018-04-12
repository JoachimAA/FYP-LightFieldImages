#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "SoundManager.h"
#include "SceneManager.h"


using namespace std;

	class Game {

	public:
		Game();
		void load();
		void run();
		void update(sf::RenderWindow &window, sf::Clock &gameClock);
		void render(sf::RenderWindow &window);
	private:

		SceneManager* m_sceneManager;
		sf::Clock m_gameClock;  //gameclock for timing
		sf::RenderWindow m_window;

	};

#endif

