#include "SceneManager.h"


void SceneManager::loadScenes(int levels)
{
	for (int i = 0; i < levels; i++)
	{
		if (i == 0)
		{
			m_scenes.push_back(new SplashScreen());
		}
		else
			m_scenes.push_back(new GameScene());
	}

	m_currentScene = 0;
	m_scenes[m_currentScene]->load();
	
}

void SceneManager::renderScene(sf::RenderWindow &window)
{
	m_scenes[m_currentScene]->render(window);
}


void SceneManager::updateScene(sf::RenderWindow &window)
{// 0 back to menu 1 scene index 2 scene index
	if (m_scenes[m_currentScene]->update(window) == 0)
	{	
		backToMenu();
	} else 
		if (m_scenes[m_currentScene]->update(window) == 1)
		{
			nextScene(1);
	    } else
		    if (m_scenes[m_currentScene]->update(window) == 2)
		    {
				nextScene(2);
		    }

	

}

void SceneManager::nextScene(int sceneValue)
{
	m_currentScene = sceneValue;
	m_scenes[m_currentScene]->load();
}

void SceneManager::backToMenu()
{
	m_currentScene = 0;
//	m_scenes[m_currentScene]->load();
}
