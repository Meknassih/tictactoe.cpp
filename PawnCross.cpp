#include "PawnCross.h"

PawnCross::PawnCross(int boardWidth, int boardHeight, int padding, int x, int y) 
	: Pawn(boardWidth, boardHeight, padding, x, y)
{
}

int PawnCross::draw(SDL_Renderer* renderer)
{
	Uint8* r = new Uint8(),
		* g = new Uint8(),
		* b = new Uint8(),
		* a = new Uint8();
	int err = 0;

	// Save previous render color
	err = SDL_GetRenderDrawColor(renderer, r, g, b, a);
	if (err != 0) return err;

	// Set pointer color
	err = SDL_SetRenderDrawColor(renderer, 200, 50, 50, 255);
	if (err != 0) return err;

	// Seg1 goes from top left to bottom right
	// Seg2 goes from bottom left to top right
	int seg1StarttopRight[2] = {this->width / 10, 0};
	int seg1EndtopRight[2] = {this->width -1, (this->height / 10) * 9 };
	err = SDL_RenderDrawLine(renderer, seg1StarttopRight[0], seg1StarttopRight[1], seg1EndtopRight[0], seg1EndtopRight[1]);
	if (err != 0) return err;

	// Reset to previous draw color
	err = SDL_SetRenderDrawColor(renderer, *r, *g, *b, *a);
	return err;
}
