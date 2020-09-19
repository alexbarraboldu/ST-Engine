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
	sRenderer->windowClear();
	
	renderBegin();
	render();
	renderEnd();

	renderGUI();

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
	//SDL_SetRenderDrawColor(sRenderer->getRenderer(), 255, 0, 0, 255);

	sRenderer->drawRectangle(SDL_Rect{1280/2 - 200/2, 720/2 - 200 / 2, 200, 200}, SDL_Color{ 255,255,255,255 }, true);
	
	sRenderer->drawRectangle(SDL_Rect{200,200, 200, 200}, SDL_Color{ 255,255,255,255 });

}

void Scene::renderEnd()
{

}

void Scene::renderGUI()
{

}
