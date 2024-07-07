#include "Pawn.h"

Pawn::Pawn(int boardWidth, int boardHeight, int padding, int x, int y) {
	this->padding = padding;
	this->x = x;
	this->y = y;
	width = (boardWidth / 3) - (2 * padding);
	height = (boardHeight / 3) - (2 * padding);
}
