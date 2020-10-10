#ifndef BUTTON_H
#define BUTTON_H

#include "string"

#include "../Text.h"
#include "BasicButton.h"
#include "../Structures.h"

class Button : public BasicButton
{
public:
	Button();
	Button(SDL_Rect _rect, std::string _text);
	Button(SDL_Rect _rect, std::string _text, Padding* _padding);
	~Button();

	void update();
	void render();

private:
	Text* text;
	Padding* padding;
};

#endif // !BUTTON_H
