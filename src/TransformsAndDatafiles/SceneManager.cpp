#include "SceneManager.h"
/*
void SceneManager::loadScene()
{
	m_currentScene.load();
}

void SceneManager::renderScene(sf::RenderWindow &window)
{
	m_currentScene.render(window);
}*/

void SceneManager::addScene(Scene scene)
{
	m_scenes.push_back(scene);
	if (m_scenes.size() == 1){
		m_currentScene = m_scenes[0];
	}
	if (m_scenes.size() == 2){
		m_nextScene = m_scenes[1];
	}

}
/*
void SceneManager::updateScene(sf::RenderWindow &window)
{
	if (m_currentScene.update(window))
	{
		nextScene();
	}
}

void SceneManager::nextScene()
{
	m_nextScene = m_currentScene;
	loadScene();
}*/
