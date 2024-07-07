#pragma once
#include "Pawn.h"
#include <SDL.h>

class PawnCross :
    public Pawn
{
private:
    int thickness;
    int draw(SDL_Renderer* renderer);

public:
    PawnCross(int boardWidth, int boardHeight, int padding, int thickness, int x, int y);
};

// Defines a segment with 4 coordinates
struct Segment {
    // Start point and end point coordinates
    int sx, sy, ex, ey;
};
