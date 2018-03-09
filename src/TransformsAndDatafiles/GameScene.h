#pragma once
#include "Scene.h"
#include "Background.h"
#include <fstream>
#include <sstream>
#include "InvisibleButton.h"
#include "Text.h"


using namespace std;

class GameScene : public Scene
{
public:

	InvisibleButton* m_iButton;
	Background* m_background;
	Button* m_menuButton;


	vector<Background*> vecOfBackgrounds;
	vector<InvisibleButton*> vecOfIButtons;
	vector<std::string> vecOfSounds;
//	vector<MenuButton*>;

	int m_currentBackground;
	int numOfSounds;

	ifstream file;
	string s;
	stringstream ss;

	sf::Mouse m_mouse;
};