#include "Pointer.h"
#include <SDL.h>

int Pointer::draw(SDL_Renderer* renderer, Sint32 x, Sint32 y) {
	Uint8* r = new Uint8(),
		* g = new Uint8(),
		* b = new Uint8(),
		* a = new Uint8();
	int err = 0;

	// Save previous render color
	err = SDL_GetRenderDrawColor(renderer, r, g, b, a);
	if (err != 0) return err;

	// Set pointer color
	err = SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	if (err != 0) return err;

	SDL_Rect rect{ x - width / 2, y - height / 2, width, height };
	err = SDL_RenderFillRect(renderer, &rect);
	if (err != 0) return err;

	// Reset to previous draw color
	err = SDL_SetRenderDrawColor(renderer, *r, *g, *b, *a);
	return err;
}

