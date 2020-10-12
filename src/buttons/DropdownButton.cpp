#include "DropdownButton.h"

DropdownButton::DropdownButton()
{
	text = new Text();
	padding = new Padding(1, 1, 1, 1);
}

DropdownButton::DropdownButton(SDL_Rect _rect, std::string _text)
{
	B_Rect = _rect;

	text = new Text();
	text->LoadFont("OpenSans-Regular.ttf", 10);
	text->LoadTextContent(_text.c_str());

	padding = new Padding{ (B_Rect.h / 10) * (B_Rect.h / 4), B_Rect.w / 4, (B_Rect.h / 10) * (B_Rect.h / 4), B_Rect.w / 4 };

	text->AddaptFontSizeToButton(B_Rect, padding, false);
}

DropdownButton::DropdownButton(SDL_Rect _rect, std::string _text, Padding* _padding)
{
	B_Rect = _rect;
	DP_Rect = calcDropdownButton(_rect, 30, 20);

	text = new Text();
	text->LoadFont("OpenSans-Regular.ttf", 1);
	text->LoadTextContent(_text.c_str());

	padding = _padding;

	text->AddaptFontSizeToButton(B_Rect, _padding, false);
}

DropdownButton::~DropdownButton() {}

//void DropdownButton::centerText(bool isCentered)
//{
//	text->AddaptFontSizeToButton(B_Rect, padding, isCentered);
//}

void DropdownButton::update()
{
	BasicDropdownButton::update();
}

void DropdownButton::render()
{
	BasicDropdownButton::render();
	text->RenderFont();
}
