#include "Board.h"
#include <stdexcept>

Board::Board(int windowWidth, int windowHeight) {
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	for (int i = 0; i < sizeof(pawns) / sizeof(Pawn*); i++) {
		pawns[i] = nullptr;
	}
}

int Board::draw(SDL_Renderer* renderer, Sint32 offsetX, Sint32 offsetY) {
	Uint8* r = new Uint8(),
		* g = new Uint8(),
		* b = new Uint8(),
		* a = new Uint8();
	int err = 0;

	// Save previous render color
	err = SDL_GetRenderDrawColor(renderer, r, g, b, a);
	if (err != 0) return err;

	// Set board color
	err = SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	if (err != 0) return err;

	// Draw
	SDL_Rect cols[2] = {
		{ (windowWidth / 3) + offsetX, offsetY, thickness, windowHeight - offsetY },
		{ ((windowWidth / 3) * 2) + offsetX, offsetY, thickness, windowHeight - offsetY },
	};
	SDL_Rect rows[2] = {
		{ offsetX, (windowHeight / 3) + offsetY, windowWidth - offsetX, thickness },
		{ offsetX, ((windowHeight / 3) * 2) + offsetY, windowWidth - offsetX, thickness},
	};
	for (SDL_Rect col : cols) {
		err = SDL_RenderFillRect(renderer, &col);
		if (err != 0) return err;
	}
	for (SDL_Rect row : rows) {
		err = SDL_RenderFillRect(renderer, &row);
		if (err != 0) return err;
	}

	// Reset to previous draw color
	err = SDL_SetRenderDrawColor(renderer, *r, *g, *b, *a);
	return err;
}

void Board::createPawnAt(int row, int col) {
	int x, y;
	getPosForSlot(row, col, &x, &y);
	Pawn* pawn = new Pawn(windowWidth, windowHeight, 8, x, y);
	int i = pushIntoPawnArray(pawn);
	if (i < 0) throw std::range_error("Board is full");
}

void Board::getPosForSlot(int row, int col, int* x, int* y)
{
	*x = (windowWidth / 3)* row;
	*y = (windowHeight / 3)* col;
}

int Board::pushIntoPawnArray(Pawn* pawn) {
	for (int i = 0; i < sizeof(pawns) / sizeof(Pawn*); i++) {
		if (pawns[i] == nullptr) {
			pawns[i] = pawn;
			return i;
		}
	}
	return -1;
}
