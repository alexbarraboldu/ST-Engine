#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>

class Button
{
public:
	Button();
	Button(SDL_Rect _rect);
	Button(SDL_Rect _rect, SDL_Color _color);
	~Button();

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

#endif // !BUTTON_H
