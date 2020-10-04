#include "Button.h"
#include "Singletons.h"

Button::Button()
{
	rect = { 0, 0, 200, 50 };
	buttonPressed = false;
}

Button::Button(SDL_Rect _rect)
{
	rect = _rect;
	buttonPressed = false;
}

Button::~Button() {}

void Button::update()
{
	clickToButton();
}

void Button::render()
{
	drawBasicButton();
}

void Button::clickToButton()
{
	if ((sInput->single_click || sInput->double_click || sInput->many_click) && sInput->state_button == ButtonState::PRESSED && sInput->type_button == ButtonType::LEFT_BUTTON && isMouseInButton())
	{
		buttonPressed = true;
	}
	else if (buttonPressed) buttonPressed = false;

	if ((sInput->single_click || sInput->double_click || sInput->many_click) && sInput->state_button == ButtonState::RELEASED && sInput->type_button == ButtonType::LEFT_BUTTON && isActualMouseInButton())
	{
		buttonUsed = true;
		printf("\n\nButton Used = TRUE\n");
	}
	else if (buttonUsed) buttonUsed = false;
}

void Button::drawBasicButton()
{
	SDL_Color color = { 225, 105, 105, 255 };

	SDL_SetRenderDrawColor(sRenderer->getRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(sRenderer->getRenderer(), &rect);

	SDL_SetRenderDrawBlendMode(sRenderer->getRenderer(), SDL_BLENDMODE_BLEND);

	if (buttonPressed)
	{
		SDL_SetRenderDrawColor(sRenderer->getRenderer(), color.r, color.g, color.b, Uint8(color.a / 1.55));
		SDL_RenderFillRect(sRenderer->getRenderer(), &rect);
	}
	else
	{
		SDL_SetRenderDrawColor(sRenderer->getRenderer(), color.r, color.g, color.b, Uint8(color.a / 2.55));
		SDL_RenderFillRect(sRenderer->getRenderer(), &rect);
	}
}

bool Button::isActualMouseInButton()
{
	if ((sInput->ActualMouseX > rect.x && sInput->ActualMouseX < rect.x + rect.w) && (sInput->ActualMouseY > rect.y && sInput->ActualMouseY < rect.y + rect.h))
	{
		return true;
	}
	return false;
}

bool Button::isMouseInButton()
{
	if ((sInput->mouseX > rect.x && sInput->mouseX < rect.x + rect.w) && (sInput->mouseY > rect.y && sInput->mouseY < rect.y + rect.h))
	{
		return true;
	}
	return false;
}
