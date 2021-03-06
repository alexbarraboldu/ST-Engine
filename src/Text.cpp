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

void Text::AddaptFontSizeToButton(SDL_Rect _containerRect, Padding* _padding, bool _center)
{
	int aTexW = 0, aTexH = 0;
	int aButtonWidth = _containerRect.w - (_padding->left + _padding->right);
	int aButtonHeight = _containerRect.h - (_padding->top + _padding->bottom);

	if (aButtonWidth <= 0)	aButtonWidth = _containerRect.w - 2;
	if (aButtonHeight <= 0)	aButtonHeight = _containerRect.h - 2;

	bool loopable = true;
	while (loopable)
	{
		SDL_QueryTexture(texture, NULL, NULL, &aTexW, &aTexH);
		
		if (aTexW <= aButtonWidth && aTexH <= aButtonHeight)
		{
			size++;
			ReloadFont();
			ReloadTextContent();
		}
		else
		{
			texW = aTexW;
			texH = aTexH;

			rect = _containerRect;

			//	GET MAX_Y & MIN_X OFFSET GLYPH TO REMOVE IT TO THE TEXT
			int aMaxY = 0, aMinX = 0;
			for (size_t i = 0; i < textContent.size(); i++)
			{
				int aaMaxY = 0, aaMinX = 0;
				TTF_GlyphMetrics(font, textContent[textContent.size()], &aaMinX, 0, 0, &aaMaxY, 0);

				if (aaMaxY >= aMaxY) aMaxY = aaMaxY;
				if (aaMinX >= aMinX) aMinX = aaMinX;
			}
			//-----------------------------------------------

			if (_center)	//	CENTERING TEXT INTO CONTAINER
			{
				rect.x += _containerRect.w / 2 - texW / 2;
				rect.y += _containerRect.h / 2 - texH / 2 - texH / 30;
			}
			else	//	USING GLYPH OFFSETS TO FIX POSITION
			{
				rect.x -= aMinX;
				rect.y -= aMaxY / 2 - 1;
			}

			//	GIVE TEXTURE TEXT THE APROPPIATE SIZE
			rect.w = texW;
			rect.h = texH;
		
			loopable = false;
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
	SDL_Surface* auxSurface = TTF_RenderText_Solid(font, textContent.c_str(), auxColor);
	texture = SDL_CreateTextureFromSurface(sRenderer->getRenderer(), auxSurface);

}
