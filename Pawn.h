#pragma once
#include <SDL.h>

class Pawn
{
protected:
	int width, height, padding;

public:
	int x, y;
	Pawn(int boardWidth, int boardHeight, int padding, int x, int y);
	virtual int draw(SDL_Renderer* renderer) = 0;
};

