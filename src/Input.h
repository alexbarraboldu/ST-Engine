#ifndef INPUT_H
#define INPUT_H

#include <cstdio>

#include "Id.h"

class Input : Id {
public:

	Input();
	~Input();

	//	Setters
	void setWindow(SDL_Window* window);

	//	Getters
	static Input* getInstance();

	inline bool isKeyPressed(SDL_Scancode key) const { return key_pressed[key]; };
	inline bool isKeyDown(SDL_Scancode key) const { return key_down[key]; };
	inline bool isKeyReleased(SDL_Scancode key) const { return key_released[key]; };

	//	Functions
	void updateEvents();

	void clearInput();
	void closeWindow();



	//	MOUSE MEMBERS
	//	ON MOTION
	Uint16 ActualMouseX, ActualMouseY;
	bool mouseMoving;
	//	ON CLICK
	unsigned short mouseX, mouseY;
	unsigned short RelMouseX, RelMouseY;
	ButtonState state_button;
	ButtonType type_button;
	bool single_click;
	bool double_click;
	//	MOUSEWHEEL

private:

	void keyPressedEvent(SDL_Scancode key);
	void keyReleasedEvent(SDL_Scancode key);
	void mousePressedEvent(SDL_MouseButtonEvent button);
	void mouseReleasedEvent(SDL_MouseButtonEvent button);
	void mouseMotionEvent(SDL_MouseMotionEvent motion);

	static Input* instance;
	SDL_Window* mWindow;

	//	KEYBOARD MEMBERS
	bool key_pressed[NGN_LAST_NO_USE];
	bool key_down[NGN_LAST_NO_USE];
	bool key_released[NGN_LAST_NO_USE];


};

inline void Input::keyPressedEvent(SDL_Scancode key)
{
	if (key != SDL_NUM_SCANCODES)
	{
		if (!key_down[key])
		{
			key_pressed[key] = true;
		}
		key_down[key] = true;
		key_released[key] = false;
	}
}

inline void Input::keyReleasedEvent(SDL_Scancode key)
{
	if (key != SDL_NUM_SCANCODES)
	{
		key_pressed[key] = false;
		key_down[key] = false;
		key_released[key] = true;
	}
}

inline void Input::mousePressedEvent(SDL_MouseButtonEvent button)
{
	printf("\nMouse Pressed:");
		
	state_button = ButtonState::PRESSED;

	switch (button.button)
	{
	case SDL_BUTTON_LEFT:
		type_button = ButtonType::LEFT_BUTTON;
		printf("\tLeft button");
		break;
	case SDL_BUTTON_MIDDLE:
		type_button = ButtonType::MIDDLE_BUTTON;
		printf("\tMiddle button");
		break;
	case SDL_BUTTON_RIGHT:
		type_button = ButtonType::RIGHT_BUTTON;
		printf("\tRight button");
		break;
	case SDL_BUTTON_X1:
		type_button = ButtonType::X1_BUTTON;
		printf("\tX1 button");
		break;
	case SDL_BUTTON_X2:
		type_button = ButtonType::X2_BUTTON;
		printf("\tX2 button");
		break;
	default:
		break;
	}

	if (button.clicks == 2)
	{
		double_click = true;
		printf(" | DoubleClick");
	}
	else if (button.clicks == 1)
	{
		single_click = true;
		printf(" | SingleClick");
	}
	
	mouseX = button.x;
	mouseY = button.y;

	printf("\nX: %d | Y: %d\n", mouseX, mouseY);
}

inline void Input::mouseReleasedEvent(SDL_MouseButtonEvent button)
{
	printf("\nMouse Released");

	state_button = ButtonState::RELEASED;

	RelMouseX = button.x;
	RelMouseY = button.y;
		
	printf("\nX: %d | Y: %d", RelMouseX, RelMouseY);
}

inline void Input::mouseMotionEvent(SDL_MouseMotionEvent motion)
{
	mouseMoving = true;

	ActualMouseX = motion.x;
	ActualMouseY = motion.y;
}

#endif // !INPUT_H

