#pragma once
#include "Pawn.h"

class PawnCircle :
    public Pawn
{
private:
    int thickness;
    int draw(SDL_Renderer* renderer);
    bool isPointInsideDonut(int x, int y) const;

public:
    PawnCircle(int boardWidth, int boardHeight, int padding, int thickness, int x, int y);
};

struct Point {
    int x, y;
};