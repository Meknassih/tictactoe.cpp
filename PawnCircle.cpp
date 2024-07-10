#include "PawnCircle.h"
#include <math.h>
#include <stdexcept>

PawnCircle::PawnCircle(int boardWidth, int boardHeight, int padding, int thickness, int x, int y)
	: Pawn(boardWidth, boardHeight, padding, x, y)
{
	this->thickness = thickness;
}

int PawnCircle::draw(SDL_Renderer* renderer)
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
	err = SDL_SetRenderDrawColor(renderer, 50, 50, 200, 255);
	if (err != 0) return err;

	
	for (int i = this->x; i < this->x + this->padding + this->width; i++) {
		for (int j = this->y; j < this->y + this->padding + this->height; j++) {
			if (isPointInsideDonut(i, j)) {
				err = SDL_RenderDrawPoint(renderer, i, j);
				if (err != 0) return err;
			}
		}
	}

	// Reset to previous draw color
	err = SDL_SetRenderDrawColor(renderer, *r, *g, *b, *a);
	return err;
}

bool PawnCircle::isPointInsideDonut(int x, int y) const {
	// ? Why do we have to divide padding / 2?
	struct Point centerPoint = {
		this->x + (this->padding / 2) + (this->width / 2),
		this->y + (this->padding / 2) + (this->height / 2)
	};
	double outerRadius = (this->width) / 2.0;
	double innerRadius = (this->width - this->thickness) / 2.0;
	double leftSide = pow(x - centerPoint.x, 2) + pow(y - centerPoint.y, 2);
	double outerRightSide = pow(outerRadius, 2);
	double innerRightSide = pow(innerRadius, 2);
	if (leftSide >= innerRightSide && leftSide < outerRightSide) {
		return true;
	}
	return false;
}