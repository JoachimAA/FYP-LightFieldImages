#pragma once
#include "Scene.h"
#include <SFML\Graphics.hpp>
#include <vector>

class SceneManager
{
public: 

	void addScene(Scene scene);
	//void loadScene();
	//void renderScene(sf::RenderWindow &window);
	//void updateScene(sf::RenderWindow &window);

	//void nextScene();

	Scene m_currentScene;
	Scene m_nextScene;

	std::vector<Scene> m_scenes; 
};