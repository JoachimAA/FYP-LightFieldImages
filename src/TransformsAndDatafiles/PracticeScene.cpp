#include "PracticeScene.h"

void PracticeScene::load(int level)
{
	//reading files
	file.open("../../TransformsAndDatafiles/Assets/practiceLevel" + std::to_string(level) + ".txt");
	if (file.is_open())
	{
		//sounds
		std::getline(file, s);
		ss.str(s);
		ss >> numOfSounds;
		ss.clear();
		for (int i = 0; i < numOfSounds; i++){
			std::getline(file, s);
			vecOfSounds.push_back(s);
		}
		//hints
		for (int i = 0; i < numOfSounds; i++){
			getline(file, s);
			vecOfHints.push_back(s);
		}
		//backgrounds
		for (int i = 0; i < numOfSounds; i++){
	     	getline(file, s);
			m_background = new Background(0, 0, 1280, 720, s);
			vecOfBackgrounds.push_back(m_background);
		}
		//buttons
		m_currentBackground = 0; //setting the background number
		for (int i = 0; i < numOfSounds; i++){
			float xPos, yPos, xSize, ySize;
			getline(file, s);
			ss.str(s);
			ss >> xPos;
			ss.clear();
			getline(file, s);
			ss.str(s);
			ss >> yPos;
			ss.clear();
			getline(file, s);
			ss.str(s);
			ss >> xSize;
			ss.clear();
			getline(file, s);
			ss.str(s);
			ss >> ySize;
			ss.clear();
			m_iButton = new InvisibleButton(xPos, yPos, xSize, ySize);
			vecOfIButtons.push_back(m_iButton);
		}
	}
	else {
		std::cout << "cannot open sound file" << endl;
	}
	file.close();

	//back to menu button
	m_menuButton = new Button(20, 10, 225, 50, "../../TransformsAndDatafiles/assets/Tellural.ttf", "Back to Menus", 30, sf::Color::Black);
	m_hints = new Text("../../TransformsAndDatafiles/assets/Tellural.ttf", vecOfHints[0], 100, sf::Color::Green, 270.0f, -15.0f);

	for (int i = 0; i < numOfSounds; i++){
		sceneSoundManager.loadSound(vecOfSounds[i]);
	}

	//back and forth from levels arrows
	if (level < 4) { //number of levels
		m_nextLevel = new TexturedButton(1190.0f, 340.0f, 0.13f, 0.13f, "../../TransformsAndDatafiles/assets/arrow.png");
		lastLevel = false;
	}
	if (level > 1) {
		m_previousLevel = new TexturedButton(10.0f, 340.0f, 0.13f, 0.13f, "../../TransformsAndDatafiles/assets/arrow.png");
		m_previousLevel->rotateSprite(180.0f);
		firstLevel = false;
	}

}

void PracticeScene::render(sf::RenderWindow & window)
{
	
		vecOfBackgrounds[m_currentBackground]->render(window);
		m_menuButton->render(window);
		m_menuButton->m_buttonText->render(window);

		if (lastLevel == false) {
			m_nextLevel->renderSprite(window);  //render next level arrow
		};
		if (firstLevel == false) {
			m_previousLevel->renderSprite(window);  //render previous level arrow
		};

		//if i need to render the buttons

		for (int i = 0; i < numOfSounds; i++){
			if (i != m_currentBackground){
				vecOfIButtons[i]->render(window);
			}
		}
		if (displayHint == true){
			m_hints->setMessage(vecOfHints[m_currentBackground]);
			m_hints->render(window);
		}
	
}

	int PracticeScene::update(sf::RenderWindow & window, sf::Clock &gameClock)
	{
		sf::Time elapsedTime = gameClock.getElapsedTime();  //get elapsed time
		if (elapsedTime.asSeconds() > 0.2f) {


			if (m_menuButton->mouseHovering(window) == true) {
				if (m_menuButton->mouseClicked(window) == true) {
					return 1;
				}
			}

			if (firstLevel == false) {  //goes back a level
				if (m_previousLevel->mouseHovering(window) == true) {
					if (m_previousLevel->mouseClicked(window) == true) {
						return 5;
					}
				}
			}

			if (lastLevel == false) {
				if (m_nextLevel->mouseHovering(window) == true) {
					if (m_nextLevel->mouseClicked(window) == true) {
						return 4;
					}
				}
			}

			for (int i = 0; i < numOfSounds; i++) {
				if (vecOfIButtons[i]->mouseHovering(window) == true) {
					if (vecOfIButtons[i]->mouseClicked(window) == true) {
						gameClock.restart();
						displayHint = true;
						m_currentBackground = i;
						sceneSoundManager.playSound(i);
					}
				}

			}
		}
	return 0;
}


void PracticeScene::handleInput(sf::Event & ev)
{
}
