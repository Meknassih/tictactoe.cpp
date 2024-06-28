#pragma once
#include <SDL.h>

class Board
{
	int windowWidth;
	int windowHeight;
	int thickness = 8;

public:
	Board(int windowWidth, int windowHeight);
	int draw(SDL_Renderer* renderer, Sint32 x, Sint32 y);
};

