#pragma once
#include "Scene.h"
#include "Background.h"
#include <fstream>
#include <sstream>
#include "InvisibleButton.h"


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
	//first button in text file correlates to the first sound in text file
	string buttonFiles = "../../TransformsAndDatafiles/Assets/level1Buttons.txt";
	string soundFiles = "../../TransformsAndDatafiles/Assets/level1Sounds.txt";
	string backgroundFiles = "../../TransformsAndDatafiles/Assets/level1Backgrounds.txt";

	ifstream file;
	string s;
	stringstream ss;

	void load() override;
	void render(sf::RenderWindow &window) override;
	bool update(sf::RenderWindow &window) override;



	sf::Mouse m_mouse;
};