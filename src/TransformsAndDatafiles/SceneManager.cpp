#include "SceneManager.h"


void SceneManager::loadScene()
{
	//push back a splash screen
	m_scenes.push_back(new SplashScreen());
	m_currentScene = 0;  //make current scene splash screen
	



	for (int i = 0; i < m_spellingLevels; i++){
		m_scenes.push_back(new SpellingScene());  //pushing back spelling levels
		m_scenes[i + 1]->load(i + 1);     //loading 
	}
	
	for (int i = 0; i < m_AlphabetLevels; i++){
		m_scenes.push_back(new PracticeScene());  //pushing practice levels into vector
		m_scenes[i + m_spellingLevels + 1]->load(i + 1);  //loading levels
	}

	m_scenes[m_currentScene]->load(0);  //load splash screen

	
}

void SceneManager::renderScene(sf::RenderWindow &window)
{
	//render current scene
	m_scenes[m_currentScene]->render(window);
}


void SceneManager::updateScene(sf::RenderWindow &window, sf::Clock &gameClock)
{
	//1 return to menu
	//2 spelling scene 
	//3 alphabet scene
	//4 next level
	//5 previous level

	m_updateReturn = m_scenes[m_currentScene]->update(window, gameClock);  //updates current scene

	//if it returns a number then go to wnext scene
	switch (m_updateReturn)
	{
	case 1: 
		backToMenu();
		break;
	case 2:
		nextScene(2, gameClock);
		break;
	case 3:
		nextScene(3, gameClock);
		break;
	case 4:
		nextScene(4, gameClock);
		break;
	case 5:
		nextScene(5, gameClock);
		break;
	}
}

//dictates next scene to go to
void SceneManager::nextScene(int level, sf::Clock &gameClock)
{

	//changes current scene
	switch (level)
	{
	case 2:
		m_currentScene = 1;
		break;
	case 3:
		m_currentScene = m_spellingLevels + 1; //amount of spelling levels + 1 index so it gets the first alphabet level
		break;
	case 4:
		m_currentScene++;
		break;
	case 5:
		m_currentScene--;
		break;
	}
	gameClock.restart();//restart game clock
}

//takes you back to splash screen
void SceneManager::backToMenu()
{
	m_currentScene = 0;
}

//handle input of current scene
void SceneManager::handleInput(sf::Event &ev)
{
	m_scenes[m_currentScene]->handleInput(ev);
}
