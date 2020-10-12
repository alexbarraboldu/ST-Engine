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

struct Sprite{

	Sprite(SDL_Texture* _texture)
	{
		texture = _texture;
		rect = NULL;
	}

	SDL_Texture* texture;
	SDL_Rect* rect;

};

typedef enum class ButtonState {

	PRESSED, RELEASED, NONE

} ButtonState;

typedef enum class ButtonType {

	LEFT_BUTTON, MIDDLE_BUTTON, RIGHT_BUTTON, X1_BUTTON, X2_BUTTON, NONE

} ButtonType;

struct Padding {
	
	Padding() {}

	Padding(int _top, int _right, int _bottom, int _left)
	{
		top = _top;
		right = _right;
		bottom = _bottom;
		left = _left;
	}

	Uint16 top, right, bottom, left;
};

#endif // !STRUCUTRES_H
