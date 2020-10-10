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
	text->LoadFont("OpenSans-Regular.ttf", 10);
	text->LoadTextContent(_text.c_str());

	padding = new Padding(1, 1, 1, 1);
}

Button::Button(SDL_Rect _rect, std::string _text, Padding* _padding)
{
	B_Rect = _rect;

	text = new Text();
	text->LoadFont("OpenSans-Regular.ttf", 30);
	text->LoadTextContent(_text.c_str());

	padding = _padding;

	text->AddaptFontSizeToWidth(B_Rect.w - (padding->left + padding->right), B_Rect, *padding);
}

Button::~Button() {}

void Button::update()
{
	BasicButton::update();
}

void Button::render()
{
	BasicButton::render();
	text->RenderFont();
}
