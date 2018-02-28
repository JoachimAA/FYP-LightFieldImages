#include "SpellingScene.h"


void SpellingScene::load(int level)
{
	//reading sound files
	file.open("../../TransformsAndDatafiles/Assets/level" + std::to_string(level) + "Sounds.txt");
	if (file.is_open())
	{
		std::getline(file, s);
		ss.str(s);
		ss >> numOfSounds;
		ss.clear();
		for (int i = 0; i < numOfSounds; i++)
		{
			std::getline(file, s);
			vecOfSounds.push_back(s);

		}
	}
	else {
		std::cout << "cannot open sound file" << endl;
	}
	file.close();

	//reading background files
	file.open("../../TransformsAndDatafiles/Assets/level" + std::to_string(level) + "Backgrounds.txt");
	if (file.is_open())
	{
		for (int i = 0; i < numOfSounds; i++)
		{
			getline(file, s);
			m_background = new Background(0, 0, 1280, 720, s);
			vecOfBackgrounds.push_back(m_background);
		}
		m_currentBackground = 0; //setting the background number
	}
	file.close();



	//reading button files
	file.open("../../TransformsAndDatafiles/Assets/level" + std::to_string(level) + "Buttons.txt");
	if (file.is_open())
	{
		for (int i = 0; i < numOfSounds; i++)
		{
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
		std::cout << "cannot open button file\n";
	}



	for (int i = 0; i < numOfSounds; i++)
	{
		sceneSoundManager.loadSound(vecOfSounds[i]);

	}


	//ANSWERS
	file.open("../../TransformsAndDatafiles/Assets/level" + std::to_string(level) + "Answers.txt");
	if (file.is_open())
	{
		for (int i = 0; i < numOfSounds; i++)
		{
			getline(file, s);
			vecOfAnswers.push_back(s);
		}
		m_currentBackground = 0; //setting the background number
	}
	file.close();

	//back to menu button
	m_menuButton = new Button(20, 10, 225, 50, "../../TransformsAndDatafiles/assets/Tellural.ttf", "Back to Menus", 30, sf::Color::Black);
	//check answer button
	m_checkButton = new Button(200.0f, 200.0f, 225.0f, 50.0f, "../../TransformsAndDatafiles/assets/Tellural.ttf", "Check answer", 30, sf::Color::Black);
	//answer typing spot
	answer = new Text("../../TransformsAndDatafiles/assets/Tellural.ttf", "", 50, sf::Color::Black, 450.0f, 10.0f);
}



void SpellingScene::render(sf::RenderWindow & window)
{
	vecOfBackgrounds[m_currentBackground]->render(window);
	m_menuButton->render(window);
	m_menuButton->m_buttonText->render(window);
	m_checkButton->render(window);
	m_checkButton->m_buttonText->render(window);
	answer->render(window);

	//if i need to render the buttons

	for (int i = 0; i < numOfSounds; i++)
	{
		if (i != m_currentBackground)
		{
			vecOfIButtons[i]->render(window);
		}
	}
}

int SpellingScene::update(sf::RenderWindow & window, sf::Clock &gameClock)
{
	for (int i = 0; i < numOfSounds; i++)
		if (vecOfIButtons[i]->mouseHovering(window) == true)
		{
			if (vecOfIButtons[i]->mouseClicked(window) == true)
			{
				m_currentBackground = i;
				sceneSoundManager.playSound(i);
			}
		}

	if (m_menuButton->mouseHovering(window) == true)
	{
		if (m_menuButton->mouseClicked(window) == true)
		{
			return 3;
		}
	}
	if (m_checkButton->mouseHovering(window) == true){
		if (m_checkButton->mouseClicked(window) == true){
			if (typeIn == vecOfAnswers[m_currentBackground]){

			  
			}
		}
	}
	return 0;
}


void SpellingScene::handleInput(sf::Event & ev)
{
	if (ev.text.unicode < 127 || ev.text.unicode > 31)
	{
		typeIn += static_cast<char>(ev.text.unicode);
		answer->setMessage(typeIn);
	}
	if (ev.text.unicode == '\b'){
		if (typeIn.size() > 1){
			typeIn.erase(typeIn.size() - 2, 2);  //erase the last two by two because the backspace is registered as a spot by the string
			answer->setMessage(typeIn);
		}
	}
}
