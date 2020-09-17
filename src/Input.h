#ifndef INPUT_H
#define INPUT_H

#include "Id.h"

class Input : Id {
public:

	Input();
	~Input();

	//	Setters
	void setWindow(SDL_Window* window);

	//	Getters
	static Input* getInstance();

	inline bool isKeyPressed(SDL_Scancode key) { return key_pressed[key]; };
	inline bool isKeyDown(SDL_Scancode key) { return key_down[key]; };
	inline bool isKeyReleased(SDL_Scancode key) { return key_released[key]; };

	//	Functions
	void updateEvents();

	void clearInput();
	void closeWindow();

private:

	void keyPressedEvent(SDL_Scancode key);
	void keyReleasedEvent(SDL_Scancode key);

	static Input* instance;
	SDL_Window* mWindow;

	bool key_pressed[NGN_LAST_NO_USE];
	bool key_down[NGN_LAST_NO_USE];
	bool key_released[NGN_LAST_NO_USE];
};

#endif // !INPUT_H
