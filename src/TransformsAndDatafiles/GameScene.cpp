#include "GameScene.h"

void GameScene::load()
{

	vecOfBackgrounds.resize(2);
	vecOfBackgrounds[1].setUp(0, 0, 1280, 72, "../../TransformsAndDatafiles/assets/AnkylosaurusFocus.jpg");
	vecOfBackgrounds[2].setUp(0, 0, 1280, 72, "../../TransformsAndDatafiles/assets/DiplodocusFocus.jpg");



}

void GameScene::render(sf::RenderWindow & window)
{
	vecOfBackgrounds[1].render(window);
}

bool GameScene::update(sf::RenderWindow & window)
{
	return false;
}
