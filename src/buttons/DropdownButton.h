#ifndef DROPDOWN_BUTTON_H
#define DROPDOWN_BUTTON_H

#include "../Text.h"
#include "BasicDropdownButton.h"
#include "../Structures.h"

class DropdownButton : public BasicDropdownButton
{
public:
	DropdownButton();
	DropdownButton(SDL_Rect _rect, std::string);
	DropdownButton(SDL_Rect _rect, std::string _text, Padding* _padding);
	~DropdownButton();

	void centerText(bool isCentered = true);

	void update();
	void render();

private:
	Text* text;
	Padding* padding;
};


#endif // !DROPDOWN_BUTTON_H
