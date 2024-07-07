#pragma once
#include <SDL.h>
#include "Pawn.h"

constexpr int BOARD_SLOTS_COUNT = 9;
constexpr int BOARD_GRID_THICKNESS = 8;

class Board
{
private:
	int windowWidth;
	int windowHeight;
	int thickness = BOARD_GRID_THICKNESS;
	Pawn* pawns[BOARD_SLOTS_COUNT];
	int pushIntoPawnArray(Pawn* pawn);
	int drawPawns(SDL_Renderer* renderer);

public:
	Board(int windowWidth, int windowHeight);
	int draw(SDL_Renderer* renderer, Sint32 x, Sint32 y);
	void createPawnCrossAt(int row, int col);
	void createPawnCircleAt(int row, int col);
	int getXForRow(int row) const;
	int getYForCol(int col) const;
};

