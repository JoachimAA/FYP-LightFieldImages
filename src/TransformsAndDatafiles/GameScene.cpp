#include "GameScene.h"


void GameScene::load(int level)
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
	else{
		std::cout << "cannot open sound file" <<  endl;
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
	file.open("../../TransformsAndDatafiles/Assets/level" + std::to_string(level) +"Buttons.txt");
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

	m_menuButton = new Button(20,650,225,50, "../../TransformsAndDatafiles/assets/Tellural.ttf", "Back to Menus", 30 , sf::Color::Black) ;

	for (int i = 0; i < numOfSounds; i++)
	{
		sceneSoundManager.loadSound(vecOfSounds[i]);
		
	}
}

void GameScene::render(sf::RenderWindow & window)
{


	vecOfBackgrounds[m_currentBackground]->render(window);
	m_menuButton->render(window);
	m_menuButton->m_buttonText->render(window);

	//if i need to render the buttons
	/*for (int i = 0; i < numOfSounds; i++)
	{
		vecOfIButtons[i]->render(window);
	}*/
}

int GameScene::update(sf::RenderWindow & window)
{
	for(int i = 0; i < numOfSounds; i++)
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
	return 0;
}
