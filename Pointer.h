#pragma once
#include <SDL.h>

class Pointer
{
	Sint32 width = 32;
	Sint32 height = 32;

public:
	int draw(SDL_Renderer* renderer, Sint32 x, Sint32 y);
};

