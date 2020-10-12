#include "BasicDropdownButton.h"
#include "../Singletons.h"

BasicDropdownButton::BasicDropdownButton() : Button()
{
	DP_Rect = { B_Rect.x + B_Rect.w - 25, B_Rect.y + B_Rect.h - 25, 25, 25};
	DP_Color = B_Color;
	DP_Pressed = false;
	DP_Used = false;

	isBoxOpen = false;
}

BasicDropdownButton::BasicDropdownButton(Uint16 W, Uint16 H) : Button()
{
	DP_Rect = { B_Rect.x + B_Rect.w - W, B_Rect.y + B_Rect.h - H, W, H };
	DP_Color = B_Color;
	DP_Pressed = false;
	DP_Used = false;

	isBoxOpen = false;
}

BasicDropdownButton::BasicDropdownButton(Uint16 W, Uint16 H, SDL_Color _color) : Button()
{
//	DP_Rect = { B_Rect.x + B_Rect.w - W, B_Rect.y + B_Rect.h - H, W, H };
	DP_Rect = calcDropdownButton(B_Rect, W, H);
	DP_Color = _color;
	DP_Pressed = false;
	DP_Used = false;

	isBoxOpen = false;
}

BasicDropdownButton::~BasicDropdownButton() {}

void BasicDropdownButton::update()
{
	clickToButton(DP_Rect, DP_Pressed, DP_Used);
	openBoxUpdate();
}

void BasicDropdownButton::render()
{
	BasicButton::render();
	basicButtonDraw(DP_Rect, DP_Color, DP_Pressed, false);
	openBoxDraw();
}

void BasicDropdownButton::openBoxUpdate()
{
	if (DP_Used && !isBoxOpen)
	{
		isBoxOpen = true;
	}
	else if (DP_Used && isBoxOpen)
	{
		isBoxOpen = false;
	}
}

void BasicDropdownButton::openBoxDraw()
{
	if (isBoxOpen)
	{
		SDL_SetRenderDrawBlendMode(sRenderer->getRenderer(), SDL_BLENDMODE_BLEND);

		SDL_SetRenderDrawColor(sRenderer->getRenderer(), B_Color.r, B_Color.g, B_Color.b, Uint8(B_Color.a / 2.55));
		SDL_RenderFillRect(sRenderer->getRenderer(), new SDL_Rect{ B_Rect.x, B_Rect.y + B_Rect.h, B_Rect.w, B_Rect.h * 3 });
	}
}
