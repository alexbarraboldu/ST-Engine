#ifndef BASIC_DROP_DOWN_BUTTON_H
#define BASIC_DROP_DOWN_BUTTON_H

#include "BasicButton.h"

class BasicDropdownButton : public BasicButton
{
public:
	BasicDropdownButton();
	BasicDropdownButton(Uint16 W, Uint16 H);
	BasicDropdownButton(Uint16 W, Uint16 H, SDL_Color _color);
	~BasicDropdownButton();

	virtual void update();
	virtual void render();

private:
	void openBoxUpdate();
	void openBoxDraw();

	SDL_Rect DP_Rect;
	SDL_Color DP_Color;
	bool DP_Pressed;
	bool DP_Used;

	bool isBoxOpen;
};

#endif // !BASIC_DROP_DOWN_BUTTON_H
