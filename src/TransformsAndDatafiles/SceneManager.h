#pragma once
#include "Scene.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include "SplashScreen.h"
#include "SpellingScene.h"
#include "PracticeScene.h"

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
	int m_spellingLevels = 4; //number of each level
	int m_AlphabetLevels = 4;
	int m_updateReturn;   //updates the return value so if a button is pressed you know where to go 

	std::vector<Scene*> m_scenes; //stores all scenes
private:
};