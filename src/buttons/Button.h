#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>

class Button
{
public:
	Button();
	Button(SDL_Rect _rect);
	~Button();

	virtual void update();
	virtual void render();

protected:
	void clickToButton();
	void drawBasicButton();


	bool isActualMouseInButton();
	bool isMouseInButton();

	SDL_Rect rect;
	bool buttonPressed;
	bool buttonUsed;
};

#endif // !BUTTON_H
