#include "DropdownButton.h"
#include "../Singletons.h"

DropdownButton::DropdownButton() : Button()
{
}

DropdownButton::~DropdownButton()
{
}

void DropdownButton::update()
{
	clickToButton();
	dropdownButton();
}

void DropdownButton::render()
{
	drawBasicButton();
	dropdownDraw();
}

void DropdownButton::dropdownButton()
{
	if (sInput->isKeyPressed(SDL_SCANCODE_C)) {
		printf("\nDropdown Button Update\n");
	}
}

void DropdownButton::dropdownDraw()
{
	if (sInput->isKeyPressed(SDL_SCANCODE_B)) {
		printf("\nDropdown Button Render\n");
	}
}

