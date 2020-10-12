#ifndef DP_BUTTON_INTERFACE_H
#define DP_BUTTON_INTERFACE_H

#include <SDL.h>

class DpButtonInterface
{
protected:
	virtual SDL_Rect calcDropdownButton(SDL_Rect _og_rect, Uint16 W, Uint16 H) {
		return SDL_Rect{ _og_rect.x + _og_rect.w - W, _og_rect.y + _og_rect.h - H, W, H };
	};

};

#endif // !DP_BUTTON_INTERFACE_H

