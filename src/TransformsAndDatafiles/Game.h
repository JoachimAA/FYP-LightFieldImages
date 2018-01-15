#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>

	using namespace std;

	class Game {

	public:
		Game();
		void load();
		void run();
		void update();
		void render();
	private:

		sf::RenderWindow window;

	};

#endif

