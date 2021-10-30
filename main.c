#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "Game.h"
#include "Common/Log.h"

int main(int argc, char *argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Init(SDL_INIT_VIDEO);

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
            "An SDL2 window",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_RESIZABLE
            );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    TimeInfo time;
    time.currentTime = SDL_GetTicks();
    time.previousTime = 0;
    time.delta = 0;
    time.MS_PER_UPDATE = 0.15f;

    int running = 1;
    float c = 0.0;

    SDL_Rect r = {10,10,10,10};

    float x = 0.0f;
    float y = 0.0f;

    while (running)
    {
        time.previousTime = time.currentTime;
        time.currentTime = SDL_GetTicks();
        time.delta = time.currentTime - time.previousTime;
        c += 0.01;

        /* Poll for and process events */
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q)
            {
                SDL_Quit();
                break;
                // End the loop.
            }
        } // End Event Checks

        if(time.delta > time.MS_PER_UPDATE)
        {
            time.delta = time.MS_PER_UPDATE;
        }

        update(time.delta);

        SDL_RenderClear(renderer);

        render();
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
