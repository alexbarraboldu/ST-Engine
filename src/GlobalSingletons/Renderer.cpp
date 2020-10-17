#include <SDL_image.h>

#include <cstdlib>
#include <ctime>

#include "../Singletons.h"

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

void Renderer::drawWhiteNoise()
{
	//regenerateWhiteNoise(whiteNoise);

	SDL_Color color = { 0, 0, 0, 255 };

	for (size_t j = 0; j < whiteNoise->area.h; j++)
	{
		for (size_t i = 0; i < whiteNoise->area.w; i++)
		{
			if (whiteNoise->noise[j][i])
			{
				color = { 255, 255, 255, 255 };
				SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
			}
			else
			{
				color = { 0, 0, 0, 255 };
				SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
			}

			SDL_RenderDrawPoint(mRenderer, i, j);
		}
	}
}

void Renderer::drawPerlinNoise1D()
{
	regeneratePerlinNoise1D(perlinNoise1D);

	SDL_Color color = { 255, 255, 255, 255 };
	SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);

	SDL_Rect rect = {};

	/*int s = 1;
	if ((rand() % 2) == 0) s = -1;

	perlinNoise1D->noise[rand() % perlinNoise1D->noise.size()]->x += s;
	perlinNoise1D->noise[rand() % perlinNoise1D->noise.size()]->y += s;*/

	for (size_t i = 0; i < perlinNoise1D->noise.size(); i++)
	{

		//	DRAW LINES
		if (i < perlinNoise1D->noise.size() - 1)
		{
			SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
			SDL_RenderDrawLine(mRenderer, perlinNoise1D->noise[i]->x, perlinNoise1D->noise[i]->y, perlinNoise1D->noise[i + 1]->x, perlinNoise1D->noise[i + 1]->y);
		}

		//	DRAW POINTS
		//SDL_SetRenderDrawColor(mRenderer, color.r, 0, 0, color.a);
		//rect = { int(perlinNoise1D->noise[i]->x), int(perlinNoise1D->noise[i]->y), 3, 3 };
		//SDL_RenderDrawRect(mRenderer, &rect);
	}
}

void Renderer::drawPerlinNoise2D()
{

}

WhiteNoise* Renderer::generateWhiteNoise(SDL_Rect rect)
{
	WhiteNoise* result = new WhiteNoise();
	result->area = rect;
	result->noise = new bool* [rect.h];
	for (size_t h = 0; h < rect.h; h++)
	{
		result->noise[h] = new bool[rect.w];
	}

	std::srand(std::time(nullptr));
	bool isWhite = true;

	for (size_t j = 0; j < rect.h; j++)
	{
		for (size_t i = 0; i < rect.w; i++)
		{
			isWhite = rand() % 2 - 1;

			result->noise[j][i] = isWhite;
		}
	}

	return result;
}

void Renderer::regenerateWhiteNoise(WhiteNoise* WhiteNoise)
{
	std::srand(std::time(nullptr));
	bool isWhite = true;

	for (size_t j = 0; j < WhiteNoise->area.h; j++)
	{
		for (size_t i = 0; i < WhiteNoise->area.w; i++)
		{
			isWhite = rand() % 2 - 1;

			WhiteNoise->noise[j][i] = isWhite;
		}
	}

}

PerlinNoise1D* Renderer::generatePerlinNoise1D(SDL_Rect rect, int nodes)
{
	PerlinNoise1D* result = new PerlinNoise1D();
	result->area = rect;
	result->noise.resize(nodes);
	result->nodes = nodes;

	std::srand(std::time(nullptr));

	for (size_t i = 0; i < result->noise.size(); i++)
	{
		result->noise[i] = new Vector2{ float(i) * result->area.w / result->noise.size(), rand() % (result->area.h / 2) + float(result->area.h / 4) };
	}

	return result;
}

void Renderer::regeneratePerlinNoise1D(PerlinNoise1D* perlinNoise1D, bool resize)
{
	std::srand(std::time(nullptr));

	if (resize)
	{
		perlinNoise1D->noise.resize(rand() % perlinNoise1D->nodes + 10);
	}

	for (size_t i = 0; i < perlinNoise1D->noise.size(); i++)
	{
		perlinNoise1D->noise[i] = new Vector2{ float(i) * perlinNoise1D->area.w / perlinNoise1D->noise.size(),
			float(perlinNoise1D->area.h / 2 + rand() % perlinNoise1D->area.h) };
	}
}