#ifndef BASIC_DROP_DOWN_BUTTON_H
#define BASIC_DROP_DOWN_BUTTON_H

#include "Button.h"
#include "../Interfaces/DpButtonInterface.h"

class BasicDropdownButton : public Button, public DpButtonInterface
{
public:
	BasicDropdownButton();
	BasicDropdownButton(Uint16 W, Uint16 H);
	BasicDropdownButton(Uint16 W, Uint16 H, SDL_Color _color);
	~BasicDropdownButton();

	virtual void update();
	virtual void render();

protected:
	void openBoxUpdate();
	void openBoxDraw();

	SDL_Rect DP_Rect;
	SDL_Color DP_Color;
	bool DP_Pressed;
	bool DP_Used;

	bool isBoxOpen;
};

#endif // !BASIC_DROP_DOWN_BUTTON_H
