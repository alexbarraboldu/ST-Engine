#include "Singletons.h"

Input* Input::instance = NULL;

Input::Input() : Id()
{
	if (instance != NULL) return;

	id = GlobalVar::QUITE_ENGINE_LOOP;

	//	ON MOTION
	ActualMouseX = 0, ActualMouseY = 0;
	//	ON CLICK
	mouseX = 0, mouseY = 0;
	RelMouseX = 0, RelMouseY = 0;
	state_button = ButtonState::NONE;
	type_button = ButtonType::NONE;
	single_click = false, double_click = false;
	//	MOUSEWHEEL

}

Input::~Input() {}


//	SETTERS

void Input::setWindow(SDL_Window* window)
{
	mWindow = window;
}


//	GETTERS

Input* Input::getInstance()
{
	if (!instance)
	{
		instance = new Input();
	}
	return instance;
}


//	FUNCTIONS

void Input::updateEvents()
{
	if (mWindow == NULL) return;

	//	RESET INPUTS
	//--------------------------------------------
	for (size_t i = 0; i < NGN_LAST_NO_USE; i++)
	{
		key_pressed[i] = false;
		key_released[i] = false;
	}
	
	if (state_button == ButtonState::RELEASED) mouseX = 0, mouseY = 0;
	//RelMouseX = 0, RelMouseY = 0;
	//state_button = ButtonState::NONE;
	//type_button = ButtonType::NONE;
	//single_click = false, double_click = false;
	//--------------------------------------------


	SDL_Event event;

	if (SDL_PollEvent(&event) > 0)
	{
		switch (event.type)
		{
		case SDL_QUIT:
			closeWindow();
			break;
		case SDL_KEYDOWN:
			keyPressedEvent(event.key.keysym.scancode);
			break;
		case SDL_KEYUP:
			keyReleasedEvent(event.key.keysym.scancode);
			break;
		case SDL_MOUSEBUTTONDOWN:
			mousePressedEvent(event.button);
			break;
		case SDL_MOUSEBUTTONUP:
			mouseReleasedEvent(event.button);
			break;
		case SDL_MOUSEMOTION:
			mouseMotionEvent(event.motion);
			break;
		default:
			break;
		}
	}


	if (isKeyPressed(SDL_SCANCODE_ESCAPE))	//	CERRAR PROGRAMA
	{
		sGlobalVariables->setQuiteEngineLoop(false, id);
	}

	if (isKeyPressed(SDL_SCANCODE_F11))	//	HACER VENTANA FULLSCREEN CON F11
	{
		if (SDL_GetWindowFlags(mWindow) & SDL_WINDOW_FULLSCREEN_DESKTOP)
		{
			SDL_SetWindowFullscreen(mWindow, 0);
		}
		else
		{
			SDL_SetWindowFullscreen(mWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
	}

}

void Input::clearInput()
{
	for (size_t i = 0; i < NGN_LAST_NO_USE; i++)
	{
		key_pressed[i] = false;
		key_down[i] = false;
		key_released[i] = false;
	}
}

void Input::closeWindow()
{
	sGlobalVariables->setQuiteEngineLoop(false, id);
}

/*
//	PRIVATE
*/

//void Input::keyPressedEvent(SDL_Scancode key)
//{
//	if (key != SDL_NUM_SCANCODES)
//	{
//		if (!key_down[key])
//		{
//			key_pressed[key] = true;
//		}
//		key_down[key] = true;
//		key_released[key] = false;
//	}
//}

//void Input::keyReleasedEvent(SDL_Scancode key)
//{
//	if (key != SDL_NUM_SCANCODES)
//	{
//		key_pressed[key] = false;
//		key_down[key] = false;
//		key_released[key] = true;
//	}
//}
