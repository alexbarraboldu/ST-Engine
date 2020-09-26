#include "Singletons.h"
#include <SDL_image.h>

Renderer* Renderer::instance = NULL;

Renderer::Renderer() : Id()
{
	if (instance != NULL) return;

	id = GlobalVar::WIDTH_HEIGHT;
	mWindow = NULL;
	mRenderer = NULL;

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

	//	NO IMPLEMENTAR
	//mScreenSurface = SDL_GetWindowSurface(mWindow);
	//	auxSurface = IMG_Load("cpp.png");
	

	//	PARA HACER RESIZE DE VENTANA
	/*SDL_RenderSetLogicalSize(mRenderer, 400, 400);*/
}

void Renderer::initRenderer()
{
	mRenderer = SDL_CreateRenderer(mWindow, -1, 0);


	//	ESTA TEXTURA ES SE VA ACUTALIZANDO
	mRenderTexture = SDL_CreateTextureFromSurface(mRenderer, auxSurface);

}


void Renderer::windowClear()
{
	SDL_RenderClear(mRenderer);
}

void Renderer::windowRefresh()
{
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);

	SDL_RenderPresent(mRenderer);
}

void Renderer::drawPoint(int x, int y, SDL_Color color)
{
	SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(mRenderer, x, y);

	//SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
}

void Renderer::drawLine(int x1, int y1, int x2, int y2, SDL_Color color)
{
	SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(mRenderer, x1, y1, x2, y2);

	//SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
}

void Renderer::drawRectangle(SDL_Rect rect, SDL_Color color, bool outline)
{
	SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
	
	if (!outline)
	{
		SDL_RenderFillRect(mRenderer, &rect);
	}
	SDL_RenderDrawRect(mRenderer, &rect);

	//SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
}

void Renderer::drawCircle()
{

}

void Renderer::drawFillTrinagleWithPoints(int x, int y, int w, int h, SDL_Color color)
{
	SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);

	int e = 0;
	for (size_t i = y; i < y + h; i++)
	{
		for (size_t j = x; j < x + w - e; j++)
		{
			SDL_RenderDrawPoint(mRenderer, i, j);
		}
		e++;
	}

	//SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
}

void Renderer::drawFillRectWithPoints(int x, int y, int w, int h, SDL_Color color)
{
	SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);

	for (size_t i = y; i < y + h; i++)
	{
		for (size_t j = x; j < x + w ; j++)
		{
			SDL_RenderDrawPoint(mRenderer, i, j);
		}
	}

	//SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
}

void Renderer::drawFillCircleWithPoints(int x, int y, int d, SDL_Color color)
{
	SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);

	int e = 0;
	for (size_t i = y; i < y + d; i++)
	{
		for (size_t j = (x + d / 2) - e; j < x + d; j++)
		{
			SDL_RenderDrawPoint(mRenderer, i, j);
		}
		e++;
	}

	//SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
}

void Renderer::drawSprite(const char* name , SDL_Rect rect)
{
	//if (name);

	int ID = sResourceManager->getSpriteID(name);

	Sprite* spr = sResourceManager->getSpriteByID(ID);
	spr->rect = &rect;

	SDL_RenderCopy(mRenderer, spr->texture, NULL, spr->rect);
}

void Renderer::drawText()
{

}