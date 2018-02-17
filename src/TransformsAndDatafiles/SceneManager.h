#pragma once
//#include "Scene.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include "SplashScreen.h"
#include "GameScene.h"

class SceneManager
{
public: 

	void loadScenes(int levels);
	void renderScene(sf::RenderWindow &window);
	void updateScene(sf::RenderWindow &window);


	void nextScene(int sceneValue);
	void backToMenu();

	int m_currentScene;



	std::vector<Scene*> m_scenes; 
};