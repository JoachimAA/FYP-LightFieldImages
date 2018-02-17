#pragma once
//#include "Scene.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include "SplashScreen.h"
#include "GameScene.h"

class SceneManager
{
public: 

	void loadScene();
	void renderScene(sf::RenderWindow &window);
	void updateScene(sf::RenderWindow &window);


	void nextScene(int level);
	void backToMenu();

	int m_currentScene;



	std::vector<Scene*> m_scenes; 
};