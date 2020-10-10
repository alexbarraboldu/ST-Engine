#include "Text.h"
#include "Singletons.h"

Text::Text()
{
	rect.x = 0;
	rect.y = 0;
}

Text::~Text()
{
	TTF_CloseFont(font);
	font = NULL;
}

void Text::LoadFont(const char* font_name, Uint8 _size)
{
	fontName = font_name;
	size = _size;
	font = TTF_OpenFont(font_name, size);

	if (!font)
	{
		printf("TEXT: Failed to load a font. ERROR: %s", TTF_GetError());
	}
}

void Text::LoadTextContent(const char* _textContent)
{
	textContent = _textContent;

	SDL_Color auxColor = { 255,255,255,255 };
	SDL_Surface* auxSurface = TTF_RenderText_Solid(font, _textContent, auxColor);
	texture = SDL_CreateTextureFromSurface(sRenderer->getRenderer(), auxSurface);

	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

	rect.w = texW;
	rect.h = texH;
}

void Text::AddaptFontSizeToWidth(Uint16 _buttonWidth, SDL_Rect _rect, Padding _padding)
{
	int aTexW = 0, aTexH = 0;

	bool loopeble = true;
	while (loopeble)
	{
		SDL_QueryTexture(texture, NULL, NULL, &aTexW, &aTexH);
		
		if (aTexW >= _buttonWidth)
		{
			size--;
			ReloadFont();
			ReloadTextContent();
		}
		else
		{
			loopeble = false;
			texW = aTexW;
			texH = aTexH;
			
			rect = _rect;
			rect.x += (rect.w - (rect.w / 2)) - texW / 2;
			rect.y += (rect.h - (rect.h / 2) - texH / 2);
			rect.w = texW;
			rect.h = texH;
		}
	}
}

void Text::RenderFont()
{
	sRenderer->drawText(texture, rect);
}

void Text::RenderFont(SDL_Rect rect)
{
	sRenderer->drawText(texture, rect);
}

void Text::ReloadFont()
{
	if (font)
	{
		TTF_CloseFont(font);
		font = NULL;
	}

	font = TTF_OpenFont(fontName, size);

	if (!font)
	{
		printf("TEXT: Failed to reload the font. ERROR: %s", TTF_GetError());
	}
}

void Text::ReloadTextContent()
{
	SDL_Color auxColor = { 255,255,255,255 };
	SDL_Surface* auxSurface = TTF_RenderText_Solid(font, textContent, auxColor);
	texture = SDL_CreateTextureFromSurface(sRenderer->getRenderer(), auxSurface);

}
