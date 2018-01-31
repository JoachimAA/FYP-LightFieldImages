#include "GameScene.h"


void GameScene::load()
{
	vecOfBackgrounds.resize(2);

	vecOfBackgrounds[0].setUp(0, 0, 1280, 720, "../../TransformsAndDatafiles/assets/AnkylosaurusFocus.jpg");
	vecOfBackgrounds[1].setUp(0, 0, 1280, 720, "../../TransformsAndDatafiles/assets/DiplodocusFocus.jpg");
	
	m_currentBackground = 0;

	//reading sound files
	file.open(soundFiles);
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
		std::cout << "cannot open sound file\n";
	}
	file.close();

	//reading button files
	file.open(buttonFiles);
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
}

void GameScene::render(sf::RenderWindow & window)
{


	vecOfBackgrounds[m_currentBackground].render(window);


	//if i need to render the buttons
	/*for (int i = 0; i < numOfSounds; i++)
	{
		vecOfIButtons[i]->render(window);
	}*/
}

bool GameScene::update(sf::RenderWindow & window)
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
	return false;
}
