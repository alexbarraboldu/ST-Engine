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
	if (sInput->single_click && sInput->state_button == ButtonState::RELEASED && sInput->type_button == ButtonType::LEFT_BUTTON && isMouseInButton())
	{
		buttonPressed = true;
		printf("\n\nCLICK DE ACTIVACION DEL BOTON\n");
	}
	else if (buttonPressed == true) buttonPressed = false;

}

void Button::render()
{
	SDL_Color color = { 0, 120, 215, 255 };

	SDL_SetRenderDrawColor(sRenderer->getRenderer(), color.r, color.g, color.b, color.a);

	SDL_RenderDrawRect(sRenderer->getRenderer(), &rect);
}

bool Button::isMouseInButton()
{
	if ((sInput->ActualMouseX > rect.x && sInput->ActualMouseX < rect.x + rect.w) && (sInput->ActualMouseY > rect.y && sInput->ActualMouseY < rect.y + rect.h))
	{
		return true;
	}
	return false;
}
