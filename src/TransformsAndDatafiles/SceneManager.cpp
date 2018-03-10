#include "SceneManager.h"


void SceneManager::loadScene()
{
	//pushing all scene into the vector
	m_scenes.push_back(new SplashScreen());
	m_currentScene = 0;
	

	for (int i = 0; i < spellingLevels; i++){
		m_scenes.push_back(new SpellingScene());  //pushing back
		m_scenes[i + 1]->load(i + 1);     //loading 
	}
	
	for (int i = 0; i < AlphabetLevels; i++){
		m_scenes.push_back(new AlphabetScene());
		m_scenes[i + spellingLevels + 1]->load(i + 1);
	}

	m_scenes[m_currentScene]->load(0);

	
}

void SceneManager::renderScene(sf::RenderWindow &window)
{
	m_scenes[m_currentScene]->render(window);
}


void SceneManager::updateScene(sf::RenderWindow &window, sf::Clock &gameClock)
{// 3 back to menu 1 scene index 2 scene index
	//updating the current scene 

	updateReturn = m_scenes[m_currentScene]->update(window, gameClock);
	if (updateReturn == 3){
		backToMenu();
	} else if (updateReturn == 1){
		nextScene(1, gameClock);
    } else if (updateReturn == 2){
		nextScene(2, gameClock);
	}
	else if (updateReturn == 4){
		nextScene(4, gameClock);
	}
	else if (updateReturn == 5) {
		nextScene(5, gameClock);
	}
}

void SceneManager::nextScene(int level, sf::Clock &gameClock)
{

	if (level == 1){
		m_currentScene = 1;
	} else 
	if (level == 2){
		m_currentScene = spellingLevels + 1; //amount of spelling levels + 1 index so it gets the first alphabet level
	} else 
	if (level == 4){
	m_currentScene++;
	}
	if (level == 5){
	m_currentScene--;
	}
	gameClock.restart();
}

void SceneManager::backToMenu()
{
	m_currentScene = 0;
}

void SceneManager::handleInput(sf::Event &ev)
{
	m_scenes[m_currentScene]->handleInput(ev);
}
