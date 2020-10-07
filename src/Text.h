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
	void LoadText(const char* text_content);
	void RenderFont();

private:
	TTF_Font* font;
	SDL_Texture* text;
};

#endif // !TEXT_H
