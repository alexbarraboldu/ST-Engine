#ifndef RENDERER_H
#define RENDERER_H
#include "Id.h"

class Renderer : Id {
public:
	Renderer();
	~Renderer();

	//	Setters
	//void setFrameRate();

	//	Getters
	static Renderer* getInstance();

	inline SDL_Window* getWindow() { return mWindow; };

	bool windowIsOpen();

	//int getFrameRateLimit();

	//	Funtions
	void initRenderer();
	void initWindow();
	void windowClear();
	void windowReferesh();

	void drawRectangle();
	void drawCircle();

	void drawSprite();

	void drawText();

private:
	static Renderer* instance;
	SDL_Renderer* mRenderer;
	SDL_Window* mWindow;

	//	GLOBAL VARIABLES
	//int mWindowWidth, mWindowHeight;
	//int mFrameRateLimit;

};

#endif // !RENDERER_H
