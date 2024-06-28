#pragma once
#include <SDL.h>
#include "Pawn.h"

class Board
{
private:
	int windowWidth;
	int windowHeight;
	int thickness = 8;
	Pawn* pawns[6];
	void getPosForSlot(int row, int col, int* x, int* y);
	int pushIntoPawnArray(Pawn* pawn);

public:
	Board(int windowWidth, int windowHeight);
	int draw(SDL_Renderer* renderer, Sint32 x, Sint32 y);
	void createPawnAt(int row, int col);
};

