#include "SceneManager.h"


void SceneManager::loadScene()
{
	//pushing all scene into the vector
	m_scenes.push_back(new SplashScreen());
	m_currentScene = 0;
	

	for (int i = 0; i < m_spellingLevels; i++){
		m_scenes.push_back(new SpellingScene());  //pushing back
		m_scenes[i + 1]->load(i + 1);     //loading 
	}
	
	for (int i = 0; i < m_AlphabetLevels; i++){
		m_scenes.push_back(new PracticeScene());
		m_scenes[i + m_spellingLevels + 1]->load(i + 1);
	}

	m_scenes[m_currentScene]->load(0);

	
}

void SceneManager::renderScene(sf::RenderWindow &window)
{
	m_scenes[m_currentScene]->render(window);
}


void SceneManager::updateScene(sf::RenderWindow &window, sf::Clock &gameClock)
{
	//1 return to menu
	//2 spelling scene 
	//3 alphabet scene
	//4 next level
	//5 previous level

	updateReturn = m_scenes[m_currentScene]->update(window, gameClock);  //updates game

	switch (updateReturn)
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

void SceneManager::nextScene(int level, sf::Clock &gameClock)
{
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
	gameClock.restart();
}

void SceneManager::backToMenu()
{
	m_currentScene = 0;
}

void SceneManager::handleInput(sf::Event &ev)
{
	m_scenes[m_currentScene]->handleInput(ev);
}
