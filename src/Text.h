#ifndef TEXT_H
#define TEXT_H

#include <SDL_ttf.h>
#include <istream>

class Text
{
public:
	Text();
	~Text();

	void LoadFont(const char* font_name, Uint8 size);
//	void LoadFont(const char* font_name, Uint16 width);
	void LoadText(const char* text_content);
	void RenderFont();
	void RenderFont(SDL_Rect rect);

private:
	TTF_Font* font;
	SDL_Texture* text;
	Uint8 size;
	int texW, texH;
};

#endif // !TEXT_H
