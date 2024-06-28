#include <SDL.h>
#include <iostream>
#include "Pointer.h"
#include "Board.h"

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    int windowSize = 800;
	SDL_Window* window = SDL_CreateWindow("TTT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowSize, windowSize, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int mousex = 0, mousey = 0; // position of the mouse
    Pointer *pointer = new Pointer();
    Board *board = new Board(windowSize, windowSize);
    board->createPawnAt(0, 0);

    while (true) {
        SDL_Event e;
        if (SDL_WaitEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
            if (e.type == SDL_MOUSEMOTION) {
                mousex = e.motion.x;
                mousey = e.motion.y;
            }
        }

        // Draw background
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Draw board
        board->draw(renderer, 0, 0);

        // Draw pointer
        pointer->draw(renderer, mousex, mousey);

        // Render
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}