

#include <SFML\Graphics.hpp>
#include "Game.h"

using namespace std;

Game::Game() :
	window(sf::VideoMode(1280, 720), "FYP-Light_Field_Images")
{
	//setting frame rate
	window.setFramerateLimit(60);
}

void Game::load()
{
	m_soundManager.loadSound();
	run();
}

void Game::run()
{
	while (window.isOpen())
	{
		sf::Event ev;
		//Handle input
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed) window.close();
		}

		update();
		render();

	}



}


void Game::update()
{

}

void Game::render()
{
	if (play)
	{
		m_soundManager.playSound();
		play = false;
	}

	window.display();
}
