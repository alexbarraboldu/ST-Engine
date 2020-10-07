#include "Text.h"
#include "Singletons.h"

Text::Text()
{

}

Text::~Text()
{
	TTF_CloseFont(font);
	font = NULL;
}

void Text::LoadFont(const char* font_name, Uint8 size)
{
	font = TTF_OpenFont(font_name, size);

	if (!font)
	{
		printf("TEXT: Failed to load a font. ERROR: %s", TTF_GetError());
	}
}

void Text::LoadText(const char* text_content)
{
	SDL_Color auxColor = { 255,255,255,255 };
	SDL_Surface* auxSurface = TTF_RenderUTF8_Solid(font, text_content, auxColor);
	text = SDL_CreateTextureFromSurface(sRenderer->getRenderer(), auxSurface);
}


void Text::RenderFont()
{
	sRenderer->drawText(text, SDL_Rect{200,200,400,60});
}