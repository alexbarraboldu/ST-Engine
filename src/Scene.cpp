#include "Scene.h"
#include "Singletons.h"

Scene::Scene() : Id()
{
	mSceneLoaded = false;
	mPutInStack = true;
	mPreloadScene = true;
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
	if (mPreloadScene) mPreloadScene = false;
	
	sResourceManager->loadImage("cpp.png");
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
	//	Aquí se carga el background
}

void Scene::render()
{
	//	Aquí se carga

	sRenderer->drawRectangle(SDL_Rect{1280/2 - 200/2, 720/2 - 200 / 2, 200, 200}, SDL_Color{ 255,255,255,255 }, true);
	
	sRenderer->drawLine(0, 0, 300, 300 , SDL_Color{ 255,255,255,255 });

	sRenderer->drawPoint(20, 40, SDL_Color{ 255,255,255,255 });

	sRenderer->drawSprite("cpp.png", SDL_Rect{10, 10, 200, 200});
	sRenderer->drawSprite("cpp.png", SDL_Rect{100, 100, 400, 400});
}

void Scene::renderEnd()
{

}

void Scene::renderGUI()
{

}
