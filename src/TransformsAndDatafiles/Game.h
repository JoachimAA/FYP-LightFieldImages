#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "SoundManager.h"

	using namespace std;

	class Game {

	public:
		Game();
		void load();
		void run();
		void update();
		void render();
	private:

		bool play = true;


		SoundManager m_soundManager;
		sf::RenderWindow window;

	};

#endif

