#pragma once
#include "Scene.h"

class SceneManager
{
public: 
	void loadScene();
	void renderScene();

	Scene m_currentScene;
};