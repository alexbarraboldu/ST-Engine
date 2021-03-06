#ifndef TEXT_H
#define TEXT_H

#include <SDL_ttf.h>
#include <istream>

#include "Structures.h"

class Text
{
public:
	Text();
	~Text();

	void LoadFont(const char* font_name, Uint8 size);
	void LoadTextContent(const char* text_content);

	void AddaptFontSizeToButton(SDL_Rect ButtonRect, Padding* _padding, bool _center = true);
	void RenderFont();
	void RenderFont(SDL_Rect rect);

	std::string textContent;

private:
	void ReloadFont();
	void ReloadTextContent();

	const char* fontName;

	TTF_Font* font;
	SDL_Rect rect;
	SDL_Texture* texture;
	Uint8 size;
	int texW, texH;
};

#endif // !TEXT_H
