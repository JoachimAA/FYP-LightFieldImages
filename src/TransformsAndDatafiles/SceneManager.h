#pragma once
#include "Scene.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include "SplashScreen.h"
#include "SpellingScene.h"
#include "AlphabetScene.h"

class SceneManager
{
public: 

	void loadScene();
	void renderScene(sf::RenderWindow &window);
	void updateScene(sf::RenderWindow &window, sf::Clock &gameClock);
	void handleInput(sf::Event &ev);


	void nextScene(int level, sf::Clock &gameClock);
	void backToMenu();

	int m_currentScene;
	int m_spellingLevels = 4;
	int m_AlphabetLevels = 2;
	int updateReturn;

	std::vector<Scene*> m_scenes; 
};