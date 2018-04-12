

#include <SFML\Graphics.hpp>
#include "Game.h"

using namespace std;

Game::Game() :
	m_window(sf::VideoMode(1280, 720), "FYP-Light_Field_Images")
{
	//setting frame rate
	m_window.setFramerateLimit(60);
}

void Game::load()
{
	m_sceneManager = new SceneManager();
	//loading the current scene
	m_sceneManager->loadScene();

	run();
}


void Game::run()
{
	while (m_window.isOpen())
	{
		sf::Event ev;
		//Handle input
		while (m_window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed) m_window.close(); // if the window is closed close the window
			if (ev.type == sf::Event::TextEntered) //if text is entered
			{
					m_sceneManager->handleInput(ev);  //handle inputs via the scene 
			}
		}

		
		update(m_window ,m_gameClock);  //update game  
		render(m_window);  //render game
	}



}


void Game::update(sf::RenderWindow &window, sf::Clock &gameClock)
{

	//update current scene
	m_sceneManager->updateScene(window, gameClock);


}

void Game::render(sf::RenderWindow &window)
{
	//render the current scene
	m_sceneManager->renderScene(window);

	//render window
	window.display();
}
