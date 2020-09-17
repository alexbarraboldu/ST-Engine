#include "Singletons.h"

Renderer* Renderer::instance = NULL;

Renderer::Renderer() : Id()
{
	if (instance != NULL) return;

	id = GlobalVar::WIDTH_HEIGHT;
	mWindow = NULL;

	initWindow();		//	AÚN NO ESTÁ HECHO EL RENDER
}

Renderer::~Renderer() {}

Renderer* Renderer::getInstance()
{
	if (!instance)
	{
		instance = new Renderer();
	}
	return instance;
}


void Renderer::initWindow()
{
	sGlobalVariables->setFrametRate(-1, id);

	mWindow = SDL_CreateWindow("Engine ABB 0.0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sGlobalVariables->getWindowWidth(id), sGlobalVariables->getWindowHeight(id), SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);

	/*SDL_RenderSetLogicalSize(mRenderer, 400, 400);*/
}

void Renderer::initRenderer()
{
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
}