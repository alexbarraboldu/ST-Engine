#include "Scene.h"
#include "Singletons.h"

Scene::Scene() : Id()
{
	mSceneLoaded = false;
	mPutInStack = true;
	id = GlobalVar::NO_PERMISSION;
}

Scene::~Scene() {}


//	ON LOAD
void Scene::onLoad()
{
	if (!mSceneLoaded)
	{
		init();
		sInput->clearInput();
		mSceneLoaded = true;
	}
	else if (mPreloadScene)
	{
		preLoad();
		mPreloadScene = false;
	}
}

void Scene::onUpdate(double deltaTime)
{
	updateBegin(deltaTime);
	update(deltaTime);
	updateEnd(deltaTime);
}

void Scene::onRender()
{
	renderBegin();
	render();
	renderEnd();

	renderGUI();

	sRenderer->windowClear();
	sRenderer->windowRefresh();
}


//	PRELOAD

void Scene::preLoad()
{

}


//	INIT

void Scene::init()
{

}


//	UPDATE

void Scene::updateBegin(double deltaTime)
{

}

void Scene::update(double deltaTime)
{

}

void Scene::updateEnd(double deltaTime)
{

}


//	RENDER

void Scene::renderBegin()
{

}

void Scene::render()
{
	SDL_SetRenderDrawColor(sRenderer->getRenderer(), 255, 0, 0, 255);
	printf("\n ESTO ES UNA SCENE");
}

void Scene::renderEnd()
{

}

void Scene::renderGUI()
{

}