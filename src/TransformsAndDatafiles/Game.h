#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "SoundManager.h"
#include "MenuButton.h"
#include "SceneManager.h"
#include "SplashScreen.h"
#include "GameScene.h"


using namespace std;

	class Game {

	public:
		Game();
		void load();
		void run();
		void update(sf::RenderWindow &window);
		void render(sf::RenderWindow &window);
	private:

		bool play = true;
		bool game = false;


		SceneManager* m_sceneManager;

		sf::RenderWindow window;

	};

#endif

