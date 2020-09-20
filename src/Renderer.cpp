#include "Singletons.h"

Renderer* Renderer::instance = NULL;

Renderer::Renderer() : Id()
{
	if (instance != NULL) return;

	id = GlobalVar::WIDTH_HEIGHT;
	mWindow = NULL;

	initWindow();
	initRenderer();
}

Renderer::~Renderer() {}


//	SETTERS

void Renderer::setFrameRate(unsigned int frameRate)
{
	sGlobalVariables->setFrametRate(frameRate, id);
}


//	GETTERS

Renderer* Renderer::getInstance()
{
	if (!instance)
	{
		instance = new Renderer();
	}
	return instance;
}


//	FUNCTIONS

void Renderer::initWindow()
{
	sGlobalVariables->setFrametRate(-1, id);

	mWindow = SDL_CreateWindow("Engine ABB 0.0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sGlobalVariables->getWindowWidth(id), sGlobalVariables->getWindowHeight(id), SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);

	/*SDL_RenderSetLogicalSize(mRenderer, 400, 400);*/
}

void Renderer::initRenderer()
{
	mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
}


void Renderer::windowClear()
{
	SDL_RenderClear(mRenderer);

}

void Renderer::windowRefresh()
{
	SDL_RenderPresent(mRenderer);
}

void Renderer::drawRectangle(SDL_Rect rect, SDL_Color color, bool outline)
{
	//SDL_Rect rectangle = rect;
	/*SDL_Color color = _color;*/

	SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);

	if (!outline)
	{
		SDL_RenderFillRect(mRenderer, &rect);
	}
	SDL_RenderDrawRect(mRenderer, &rect);

	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
}

//void Renderer::drawRectangle()
//{
//	SDL_Rect rect = {200, 200, 200, 200};
//
//	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
//	SDL_RenderDrawRect(mRenderer, &rect);
//
//	SDL_SetRenderDrawColor(mRenderer, 0,0,0,255);
//}

void Renderer::drawCircle()
{

}

void Renderer::drawSprite()
{

}

void Renderer::drawText()
{

}