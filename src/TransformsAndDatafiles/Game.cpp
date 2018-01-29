

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


	m_menu.load();

	//adding scenes for game
	m_sceneManager.addScene(m_menu);
	m_sceneManager.addScene(level1);

	//loading the current scene
	//m_sceneManager->loadScene();

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

		update(window);
		render(window);

	}



}


void Game::update(sf::RenderWindow &window)
{

	//plays a is for apple
	if (play)
	{
		m_soundManager.playSound();
		play = false;
	}
//	m_button.mouseClicked(window);

	//update current scene
	//m_sceneManager->updateScene(window);

	

	if (m_menu.update(window))
	{
//		level1.load();
	}
}

void Game::render(sf::RenderWindow &window)
{
	//m_button.render(window);

	//render the current scene
	//m_sceneManager->renderScene(window);

	m_menu.render(window);
	//render window
	window.display();
}
