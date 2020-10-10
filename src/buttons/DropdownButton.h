#ifndef DROPDOWN_BUTTON_H
#define DROPDOWN_BUTTON_H

#include "../Text.h"
#include "BasicDropdownButton.h"
#include "../Structures.h"

class DropdownButton : public BasicDropdownButton
{
public:
	DropdownButton();
	~DropdownButton();

	void update();
	void render();

private:
	Text* text;
};


#endif // !DROPDOWN_BUTTON_H
