#pragma once
#include "Scene.h"
#include "Background.h"
#include <fstream>
#include <sstream>
#include "InvisibleButton.h"
#include "Text.h"
#include "TexturedButton.h"


using namespace std;

class GameScene : public Scene
{
public:

	InvisibleButton* m_iButton;
	Background* m_background;
	Button* m_menuButton;


	vector<Background*> m_vecOfBackgrounds;  //holds the scene backgrounds
	vector<InvisibleButton*> m_vecOfIButtons;  //holds the values of the invisible buttons
	vector<std::string> m_vecOfSounds;  //holds the scene sounds

	int m_currentBackground;  //current background needing to be displayed
	int m_numOfSounds;  //holds number of sounds 

	bool m_firstLevel = true;  //booleons to know when your on the first of last level
	bool m_lastLevel = true;

	TexturedButton * m_nextLevel;  //textured buttons in the game
	TexturedButton * m_previousLevel;

	ifstream file;
	string s;        //for file reading
	stringstream ss;

	sf::Mouse m_mouse;  //mouse to get mouse clicks

private:
};