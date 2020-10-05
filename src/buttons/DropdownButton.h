#ifndef DROP_DOWN_BUTTON_H
#define DROP_DOWN_BUTTON_H

#include "Button.h"

class DropdownButton : public Button
{
public:
	DropdownButton();
	DropdownButton(Uint16 W, Uint16 H);
	DropdownButton(Uint16 W, Uint16 H, SDL_Color _color);
	~DropdownButton();

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

#endif // !DROP_DOWN_BUTTON_H
