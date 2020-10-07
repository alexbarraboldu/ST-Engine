#include "Singletons.h"
#include <SDL_image.h>

Renderer* Renderer::instance = NULL;

Renderer::Renderer() : Id()
{
	if (instance != NULL) return;

	id = GlobalVar::WIDTH_HEIGHT;
	mWindow = NULL;
	mRenderer = NULL;
	mRenderTexture = NULL;

	initWindow();
	initRenderer();
}

Renderer::~Renderer()
{
	SDL_DestroyTexture(mRenderTexture);
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
}


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

	//	PARA HACER RESIZE DE VENTANA
	/*SDL_RenderSetLogicalSize(mRenderer, 400, 400);*/
}

void Renderer::initRenderer()
{
	mRenderer = SDL_CreateRenderer(mWindow, -1, 0);


	//	ESTA TEXTURA ES LA QUE SE VA ACUTALIZANDO
	//mRenderTexture = SDL_CreateTextureFromSurface(mRenderer, auxSurface);
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
	else SDL_RenderDrawRect(mRenderer, &rect);

	//SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
}

void Renderer::drawCircle()
{

}


void Renderer::drawSprite(const char* name , SDL_Rect rect)
{
	SDL_RenderCopy(mRenderer, sResourceManager->getSpriteByID(sResourceManager->getSpriteID(name))->texture,NULL, &rect);
}

void Renderer::drawText(SDL_Texture* text, SDL_Rect rect)
{
	SDL_RenderCopy(mRenderer, text, NULL, &rect);
}

void Renderer::drawSelection(SDL_Rect rect)
{
	if (sInput->state_button == ButtonState::PRESSED && sInput->type_button == ButtonType::LEFT_BUTTON && sInput->mouseMoving) {
		SDL_Color color = { 0, 120, 215, 255 };
		
		SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawRect(mRenderer, &rect);
		
		color = { 0, 120, 215, 100 };
		SDL_SetRenderDrawBlendMode(mRenderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);

		SDL_RenderFillRect(mRenderer, &rect);
	}
}