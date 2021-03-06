#include "Singletons.h"

GlobalVariables* sGlobalVariables = NULL;
Input* sInput = NULL;
Renderer* sRenderer = NULL;
ResourceManager* sResourceManager = NULL;
SceneDirector* sSceneDirector = NULL;
//SoundManager* sSoundManager = NULL;

const void initializeSingletons() {
	sGlobalVariables = GlobalVariables::getInstance();
	sInput = Input::getInstance();
	sRenderer = Renderer::getInstance();
	sResourceManager = ResourceManager::getInstance();
	sSceneDirector = SceneDirector::getInstance();
	//sSoundManager = SoundManager::getInstance();

	sInput->setWindow(sRenderer->getWindow());
}

const void deleteSingletons() {
	delete sGlobalVariables->getInstance();
	sGlobalVariables = NULL;

	delete sInput->getInstance();
	sInput = NULL;

	delete sRenderer->getInstance();
	sRenderer = NULL;

	delete sResourceManager->getInstance();
	sResourceManager = NULL;

	delete sSceneDirector->getInstance();
	sSceneDirector = NULL;

	//delete sSoundManager->getInstance();
	//sSoundManager = NULL;

}

