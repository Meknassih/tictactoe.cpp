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
	int drawPawns(SDL_Renderer* renderer);

public:
	Board(int windowWidth, int windowHeight);
	int draw(SDL_Renderer* renderer, Sint32 x, Sint32 y);
	void createPawnCrossAt(int row, int col);
	void createPawnCircleAt(int row, int col);
};

