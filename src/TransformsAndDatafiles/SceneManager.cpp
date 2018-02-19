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


void SceneManager::updateScene(sf::RenderWindow &window)
{// 0 back to menu 1 scene index 2 scene index
	if (m_scenes[m_currentScene]->update(window) == 3)
	{	
		backToMenu();
	} else 
	if (m_scenes[m_currentScene]->update(window) == 1)
	{
		nextScene(1);
    }
	if (m_scenes[m_currentScene]->update(window) == 2)
	{
		nextScene(2);
	}
}

void SceneManager::nextScene(int level)
{
	m_scenes.push_back(new GameScene);
	m_currentScene++;
	m_scenes[m_currentScene]->load(level);
}

void SceneManager::backToMenu()
{
	m_currentScene = 0;
	m_scenes.erase(m_scenes.end() -1);
}
