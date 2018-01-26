#pragma once
#include "Scene.h"
#include <SFML\Graphics.hpp>
#include <vector>

class SceneManager
{
public: 

	void addScene(Scene scene);
	void loadScene();
	void renderScene(sf::RenderWindow &window);

	Scene m_currentScene;

	std::vector<Scene> m_scenes;
};