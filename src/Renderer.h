#ifndef RENDERER_H
#define RENDERER_H
#include "Id.h"

class Renderer : Id {
public:
	Renderer();
	~Renderer();

	//	Setters
	void setFrameRate(unsigned int frameRate);
	void setTexture(SDL_Texture* texture) { mRenderTexture = texture; };

	//	Getters
	static Renderer* getInstance();

	inline SDL_Window* getWindow() { return mWindow; };
	inline SDL_Renderer* getRenderer() { return mRenderer; };
	inline SDL_Texture* getTexture() { return mRenderTexture; };

	bool windowIsOpen();

	//int getFrameRateLimit();

	//	Funtions
	void initWindow();
	void initRenderer();
	void windowClear();
	void windowRefresh();

	void drawPoint(int x, int y, SDL_Color color);
	void drawLine(int x1, int y1, int x2, int y2, SDL_Color color);
	void drawRectangle(SDL_Rect rect, SDL_Color color, bool outline = false);
	void drawCircle();

	//	Not Useful stuff
	void drawFillTrinagleWithPoints(int x, int y, int w, int h, SDL_Color color);
	void drawFillRectWithPoints(int x, int y, int w, int h, SDL_Color color);
	void drawFillCircleWithPoints(int x, int y, int d, SDL_Color color);
	//------------------

	void drawSprite(const char* name, SDL_Rect rect);

	void drawText();

private:
	static Renderer* instance;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	SDL_Texture* mRenderTexture;

//	SDL_Surface* mScreenSurface;

//	SDL_Surface* auxSurface;

};

#endif // !RENDERER_H
