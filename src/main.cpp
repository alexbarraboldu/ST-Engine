#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Engine.h"

int SDLflags = /*SDL_INIT_TIMER*/ /*| SDL_INIT_AUDIO |*/ SDL_INIT_VIDEO /*| SDL_INIT_JOYSTICK*//* | SDL_INIT_HAPTIC*/ /*| SDL_INIT_GAMECONTROLLER*/ | SDL_INIT_EVENTS /*| SDL_INIT_SENSOR*/ | SDL_INIT_NOPARACHUTE /*| SDL_INIT_EVERYTHING*/;
int IMG_flags = IMG_INIT_JPG | IMG_INIT_PNG /*| IMG_INIT_TIF | IMG_INIT_WEBP*/;


int main(int argc, char *argv[])
{

	if (SDL_Init(SDLflags) == -1)
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (!(IMG_Init(IMG_flags) & IMG_flags))
	{
		std::cout << "Failed to initialize SDL_Image. ERROR: " << IMG_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (TTF_Init() == -1)
	{
		std::cout << "Failed to initialize SDL_TTF. ERROR: " << TTF_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	Engine* engine1 = new Engine();

	engine1->engineLoop();
	engine1->destroy();
	delete engine1;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return EXIT_SUCCESS;
}
