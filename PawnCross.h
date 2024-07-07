#pragma once
#include "Pawn.h"
#include <SDL.h>

class PawnCross :
    public Pawn
{
private:
    int draw(SDL_Renderer* renderer);

public:
    PawnCross(int boardWidth, int boardHeight, int padding, int x, int y);
};

