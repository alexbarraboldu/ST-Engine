#ifndef RENDERER_H
#define RENDERER_H
#include "Id.h"

class Renderer : Id {
public:
	Renderer();
	~Renderer();

	//	Setters
	void setFrameRate(unsigned int frameRate);

	//	Getters
	static Renderer* getInstance();

	inline SDL_Window* getWindow() { return mWindow; };
	inline SDL_Renderer* getRenderer() { return mRenderer; };

	bool windowIsOpen();

	//int getFrameRateLimit();

	//	Funtions
	void initWindow();
	void initRenderer();
	void windowClear();
	void windowRefresh();

	void drawRectangle(SDL_Rect rect, SDL_Color color, bool outline = false);
	void drawCircle();

	void drawSprite();

	void drawText();

private:
	static Renderer* instance;
	SDL_Renderer* mRenderer;
	SDL_Window* mWindow;

};

#endif // !RENDERER_H
