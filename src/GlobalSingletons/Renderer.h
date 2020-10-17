#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "../Id.h"

class Renderer : Id {
public:
	Renderer();
	~Renderer();

	//	Setters
	void setFrameRate(unsigned int frameRate);
	void setTexture(SDL_Texture* texture) { mRenderTexture = texture; };

	//	Getters
	static Renderer* getInstance();

	inline SDL_Window* getWindow() const { return mWindow; };
	inline SDL_Renderer* getRenderer() const { return mRenderer; };
	inline SDL_Texture* getTexture() const { return mRenderTexture; };

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

	//------------------

	void drawSprite(const char* name, SDL_Rect rect);
	void drawText(SDL_Texture* text, SDL_Rect rect);
	void drawSelection(SDL_Rect rect);

	//------------------
	WhiteNoise* whiteNoise;
	WhiteNoise* generateWhiteNoise(SDL_Rect rect);
	void regenerateWhiteNoise(WhiteNoise* WhiteNoise);

	PerlinNoise1D* perlinNoise1D;
	PerlinNoise1D* generatePerlinNoise1D(SDL_Rect rect, int nodes);
	void regeneratePerlinNoise1D(PerlinNoise1D* perlinNoise1D, bool resize = false);
	
	void drawWhiteNoise();
	void drawPerlinNoise1D();
	void drawPerlinNoise2D();

private:
	static Renderer* instance;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	SDL_Texture* mRenderTexture;

//	SDL_Surface* mScreenSurface;

//	SDL_Surface* auxSurface;

};

#endif // !RENDERER_H
