#ifndef BASIC_BUTTON_H
#define BASIC_BUTTON_H

#include <SDL.h>

class BasicButton
{
public:
	BasicButton();
	BasicButton(SDL_Rect _rect);
	BasicButton(SDL_Rect _rect, SDL_Color _color);
	~BasicButton();

	virtual void update();
	virtual void render();

protected:
	void clickToButton(SDL_Rect _rect, bool &_pressed, bool &_used);
	void basicButtonDraw(SDL_Rect _rect, bool _pressed = false, bool _drawFill = true);
	void basicButtonDraw(SDL_Rect _rect, SDL_Color _color ,bool _pressed = false, bool _drawFill = true);


	bool isActualMouseInButton(SDL_Rect buttonRect);
	bool isMouseInButton(SDL_Rect buttonRect);

	SDL_Rect B_Rect;
	SDL_Color B_Color;
	bool B_Pressed;
	bool B_Used;
	bool B_DrawFill;
};

#endif // !BASIC_BUTTON_H
