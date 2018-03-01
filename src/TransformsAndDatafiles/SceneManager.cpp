#include "SceneManager.h"


void SceneManager::loadScene()
{
	m_scenes.push_back(new SplashScreen());
	m_currentScene = 0;
	m_scenes[m_currentScene]->load(0);
	
}

void SceneManager::renderScene(sf::RenderWindow &window)
{
	m_scenes[m_currentScene]->render(window);
}


void SceneManager::updateScene(sf::RenderWindow &window, sf::Clock &gameClock)
{// 3 back to menu 1 scene index 2 scene index
	//updating the current scene 

	updateReturn = m_scenes[m_currentScene]->update(window, gameClock);
	if (updateReturn == 3){
		backToMenu();
	} else if (updateReturn == 1){
		nextScene(1);
    } else if (updateReturn == 2){
		nextScene(2);
	}
}

void SceneManager::nextScene(int level)
{
	if (level == 1){
		m_scenes.push_back(new SpellingScene);
	} else
		if (level == 2){
			m_scenes.push_back(new AlphabetScene);
		}

	m_currentScene++;
	m_scenes[m_currentScene]->load(level);
}

void SceneManager::backToMenu()
{
	m_currentScene = 0;
	m_scenes.erase(m_scenes.end() -1);
}

void SceneManager::handleInput(sf::Event &ev)
{
	m_scenes[m_currentScene]->handleInput(ev);
}
