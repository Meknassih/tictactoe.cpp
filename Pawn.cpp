#include "Pawn.h"

Pawn::Pawn(int boardWidth, int boardHeight, int padding, int x, int y) {
	this->padding = padding;
	this->x = x;
	this->y = y;
	width = (boardWidth / 3) - (2 * padding);
	height = (boardHeight / 3) - (2 * padding);
}

int Pawn::draw(SDL_Renderer* renderer, Sint32 x, Sint32 y) {
	Uint8* r = new Uint8(),
		* g = new Uint8(),
		* b = new Uint8(),
		* a = new Uint8();
	int err = 0;

	// Save previous render color
	err = SDL_GetRenderDrawColor(renderer, r, g, b, a);
	if (err != 0) return err;

	// Set pointer color
	err = SDL_SetRenderDrawColor(renderer, 50, 200, 50, 255);
	if (err != 0) return err;

	// Draw
	SDL_Rect rect{ x + padding, y + padding, width, height };
	err = SDL_RenderFillRect(renderer, &rect);
	if (err != 0) return err;

	// Reset to previous draw color
	err = SDL_SetRenderDrawColor(renderer, *r, *g, *b, *a);
	return err;
}