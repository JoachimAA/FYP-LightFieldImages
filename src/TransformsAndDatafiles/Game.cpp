

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
	m_sceneManager = new SceneManager();
	//loading the current scene
	m_sceneManager->loadScene();

//	m_soundManager.loadSound();

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

		update(window);
		render(window);

	}



}


void Game::update(sf::RenderWindow &window)
{

	//update current scene
	m_sceneManager->updateScene(window);


}

void Game::render(sf::RenderWindow &window)
{
	//render the current scene
	m_sceneManager->renderScene(window);

	//render window
	window.display();
}
