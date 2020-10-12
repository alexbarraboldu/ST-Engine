#include "Button.h"
#include "../Singletons.h"

Button::Button()
{
	text = new Text();
	padding = new Padding(1,1,1,1);
}

Button::Button(SDL_Rect _rect, std::string _text)
{
	B_Rect = _rect;

	text = new Text();
	text->LoadFont("OpenSans-Regular.ttf", 1);
	text->LoadTextContent(_text.c_str());

	padding = new Padding(1, 20, 1, 20);

	text->AddaptFontSizeToButton(B_Rect, padding, false);
}

Button::Button(SDL_Rect _rect, std::string _text, Padding* _padding)
{
	B_Rect = _rect;

	text = new Text();
	text->LoadFont("OpenSans-Regular.ttf", 1);
	text->LoadTextContent(_text.c_str());

	padding = _padding;

	text->AddaptFontSizeToButton(B_Rect, padding, false);
}

Button::~Button() {}

void Button::centerText(bool isCentered)
{
	text->AddaptFontSizeToButton(B_Rect, padding, isCentered);
}

void Button::update()
{
	BasicButton::update();
}

void Button::render()
{
	BasicButton::render();
	text->RenderFont();
}
