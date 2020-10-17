#include "Scene.h"
#include "Singletons.h"

Scene::Scene() : Id()
{
	mSceneLoaded = false;
	mPutInStack = true;
	mPreloadScene = true;
	id = GlobalVar::WIDTH_HEIGHT;

	system = new System();
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
	
	sResourceManager->loadImage("Content/Images/cpp.png");
}


//	INIT

void Scene::init()
{
	system->init();

	sRenderer->whiteNoise = sRenderer->generateWhiteNoise(SDL_Rect{0,0,150,150});

	sRenderer->perlinNoise1D = sRenderer->generatePerlinNoise1D(SDL_Rect{ 0,0,500,150 }, 200);
}


//	UPDATE

void Scene::updateBegin(double deltaTime)
{

}

void Scene::update(double deltaTime)
{
	system->update();
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
	
//	sRenderer->drawRectangle(SDL_Rect{1280/2 - 200/2, 720/2 - 200 / 2, 200, 200}, SDL_Color{ 255,255,255,255 }, true);
	
//	sRenderer->drawLine(0, 0, 300, 300 , SDL_Color{ 255,255,255,255 });

//	sRenderer->drawPoint(20, 40, SDL_Color{ 255,255,255,255 });

//	sRenderer->drawSprite("Content/Images/cpp.png", SDL_Rect{600,200,200,200});

//	sRenderer->drawWhiteNoise();
	sRenderer->drawPerlinNoise1D();
}

void Scene::renderEnd()
{
//	system->render();

}

void Scene::renderGUI()
{

	//	SELECCIÓN
	sRenderer->drawSelection(SDL_Rect{sInput->mouseX, sInput->mouseY, sInput->ActualMouseX - sInput->mouseX, sInput->ActualMouseY - sInput->mouseY});
}

