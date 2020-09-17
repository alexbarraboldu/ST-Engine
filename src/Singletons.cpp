#include "Singletons.h"

GlobalVariables* sGlobalVariables = NULL;
Input* sInput = NULL;
Renderer* sRenderer = NULL;
//ResourceManager* sResourceManager = NULL;
SceneDirector* sSceneDirector = NULL;
//SoundManager* sSoundManager = NULL;

void initializeSingletons() {
	sGlobalVariables = GlobalVariables::getInstance();
	sInput = Input::getInstance();
	sRenderer = Renderer::getInstance();
	//sResourceManager = ResourceManager::getInstance();
	sSceneDirector = SceneDirector::getInstance();
	//sSoundManager = SoundManager::getInstance();

	sInput->setWindow(sRenderer->getWindow());
}