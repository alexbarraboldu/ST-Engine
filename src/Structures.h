#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <SDL.h>

typedef enum {

	FRAME_RATE = 1,
	QUITE_ENGINE_LOOP = FRAME_RATE << 1,
	WIDTH_HEIGHT = QUITE_ENGINE_LOOP << 1,
	VSYNC = WIDTH_HEIGHT << 1,
	E = VSYNC << 1,

	NO_PERMISSION = E << 1,

} GlobalVar;


typedef struct Sprite{

	Sprite(SDL_Texture* _texture)
	{
		texture = _texture;
		rect = NULL;
	}

	SDL_Texture* texture;
	SDL_Rect* rect;

};

#endif // !STRUCUTRES_H
