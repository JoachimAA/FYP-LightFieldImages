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
{
	if (m_scenes[m_currentScene]->update(window))
	{
		nextScene();
	}

}

void SceneManager::nextScene()
{
	m_currentScene++;
	m_scenes[m_currentScene]->load();
}
