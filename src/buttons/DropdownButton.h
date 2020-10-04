#ifndef DROP_DOWN_BUTTON_H
#define DROP_DOWN_BUTTON_H

#include "Button.h"

class DropdownButton : public Button
{
public:
	DropdownButton();
	~DropdownButton();

	virtual void update();
	virtual void render();

private:
	void dropdownButton();
	void dropdownDraw();
};

#endif // !DROP_DOWN_BUTTON_H
