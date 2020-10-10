#include "BasicButton.h"
#include "../Singletons.h"

BasicButton::BasicButton()
{
	B_Rect = { 0, 0, 200, 50 };
	B_Color = { 225, 105, 105, 255 };
	B_Pressed = false;
	B_Used = false;
	B_DrawFill = false;
}

BasicButton::BasicButton(SDL_Rect _rect)
{
	B_Rect = _rect;
	B_Color = { 255, 105, 105, 255};
	B_Pressed = false;
	B_Used = false;
	B_DrawFill = false;
}

BasicButton::BasicButton(SDL_Rect _rect, SDL_Color _B_Color)
{
	B_Rect = _rect;
	B_Color = _B_Color;
	B_Pressed = false;
	B_Used = false;
	B_DrawFill = false;
}


BasicButton::~BasicButton() {}

void BasicButton::update()
{
	clickToButton(B_Rect, B_Pressed, B_Used);
}

void BasicButton::render()
{
	basicButtonDraw(B_Rect, B_Pressed);
}

void BasicButton::clickToButton(SDL_Rect _rect, bool &_pressed, bool &_used)
{
	if ((sInput->single_click || sInput->double_click || sInput->many_click) && sInput->state_button == ButtonState::PRESSED && sInput->type_button == ButtonType::LEFT_BUTTON && isMouseInButton(_rect))
	{
		_pressed = true;
	}
	else if (_pressed) _pressed = false;

	if ((sInput->single_click || sInput->double_click || sInput->many_click) && sInput->state_button == ButtonState::RELEASED && sInput->type_button == ButtonType::LEFT_BUTTON && isActualMouseInButton(_rect))
	{
		_used = true;
		printf("\n\nButton Used = TRUE\n");
	}
	else if (_used/* && _pressed*/) { /*_pressed = false;*/ _used = false; }
}

void BasicButton::basicButtonDraw(SDL_Rect _rect, bool _pressed, bool _drawFill)
{
	SDL_SetRenderDrawColor(sRenderer->getRenderer(), B_Color.r, B_Color.g, B_Color.b, B_Color.a);
	SDL_RenderDrawRect(sRenderer->getRenderer(), &_rect);

	SDL_SetRenderDrawBlendMode(sRenderer->getRenderer(), SDL_BLENDMODE_BLEND);

	if (_pressed)
	{
		SDL_SetRenderDrawColor(sRenderer->getRenderer(), B_Color.r, B_Color.g, B_Color.b, Uint8(B_Color.a / 1.55));
		SDL_RenderFillRect(sRenderer->getRenderer(), &_rect);
	}
	else if (!_pressed && _drawFill)
	{
		SDL_SetRenderDrawColor(sRenderer->getRenderer(), B_Color.r, B_Color.g, B_Color.b, Uint8(B_Color.a / 2.55));
		SDL_RenderFillRect(sRenderer->getRenderer(), &_rect);
	}
}

void BasicButton::basicButtonDraw(SDL_Rect _rect, SDL_Color _color, bool _pressed, bool _drawFill)
{
	SDL_SetRenderDrawColor(sRenderer->getRenderer(), _color.r, _color.g, _color.b, _color.a);
	SDL_RenderDrawRect(sRenderer->getRenderer(), &_rect);

	SDL_SetRenderDrawBlendMode(sRenderer->getRenderer(), SDL_BLENDMODE_BLEND);

	if (_pressed)
	{
		SDL_SetRenderDrawColor(sRenderer->getRenderer(), _color.r, _color.g, _color.b, Uint8(_color.a / 1.55));
		SDL_RenderFillRect(sRenderer->getRenderer(), &_rect);
	}
	else if (!_pressed && _drawFill)
	{
		SDL_SetRenderDrawColor(sRenderer->getRenderer(), _color.r, _color.g, _color.b, Uint8(_color.a / 2.55));
		SDL_RenderFillRect(sRenderer->getRenderer(), &_rect);
	}
}

bool BasicButton::isActualMouseInButton(SDL_Rect _rect)
{
	if ((sInput->ActualMouseX > _rect.x && sInput->ActualMouseX < _rect.x + _rect.w) && (sInput->ActualMouseY > _rect.y && sInput->ActualMouseY < _rect.y + _rect.h))
	{
		return true;
	}
	return false;
}

bool BasicButton::isMouseInButton(SDL_Rect _rect)
{
	if ((sInput->mouseX > _rect.x && sInput->mouseX < _rect.x + _rect.w) && (sInput->mouseY > _rect.y && sInput->mouseY < _rect.y + _rect.h))
	{
		return true;
	}
	return false;
}
