#include "PawnCross.h"
#include <math.h>
#include <stdexcept>

PawnCross::PawnCross(int boardWidth, int boardHeight, int padding, int thickness, int x, int y) 
	: Pawn(boardWidth, boardHeight, padding, x, y)
{
	this->thickness = thickness;
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

	// Using Pythagoras theorem for isosceles right triangle : c^2 + c^2 = k^2
	int offset = (int)round(thickness / sqrt(2));

	// Allocate n segments for each vertex of the cross
	int segCount = this->thickness * 2;
	struct Segment* segments = (struct Segment*)malloc(sizeof(Segment) * segCount);
	if (segments == NULL) {
		throw std::runtime_error("Could not allocate segments");
	}
	for (int i = 0; i < segCount / 2; i++) {
		segments[i].sx = this->x + (offset - i) + padding;
		segments[i].sy = this->y + i + padding;
		segments[i].ex = this->x + (width - i) - padding;
		segments[i].ey = this->y + (height - offset) + i - padding;
	}
	int j = 0;
	for (int i = segCount / 2; i < segCount; i++) {
		segments[i].sx = this->x + (width - offset) + j - padding;
		segments[i].sy = this->y + j + padding;
		segments[i].ex = this->x + j + padding;
		segments[i].ey = this->y + (height - offset) + j - padding;
		j++;
	}

	for (int i = 0; i < segCount; i++) {
		err = SDL_RenderDrawLine(renderer, segments[i].sx, segments[i].sy, segments[i].ex, segments[i].ey);
		if (err != 0) {
			free(segments);
			return err;
		}
	}
	free(segments);

	// Reset to previous draw color
	err = SDL_SetRenderDrawColor(renderer, *r, *g, *b, *a);
	return err;
}
