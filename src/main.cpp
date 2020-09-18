#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "Engine.h"

int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;

int main(int argc, char *argv[])
{

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (!(IMG_Init(flags) & flags)) 
	{
		std::cout << "Failed to initialize SDL_Image for PNG files: " << IMG_GetError() << std::endl;
	}

	Engine* engine1 = new Engine();

	//initializeSingletons();

	engine1->engineLoop();
	engine1->destroy();

	SDL_Quit();

	return EXIT_SUCCESS;
}
