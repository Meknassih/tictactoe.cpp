#pragma once
#include <SDL.h>

class Pawn
{
private:
	int width, height, padding;

public:
	int x, y;
	Pawn(int boardWidth, int boardHeight, int padding, int x, int y);
	int draw(SDL_Renderer* renderer, Sint32 x, Sint32 y);
};

