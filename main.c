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

    int running = 1;
    int MS_PER_UPDATE = 16; // 60 FPS
    double now = SDL_GetTicks();
    double oldTime = SDL_GetTicks();
    double delta = 0.0;
    float c = 0.0;

    SDL_Rect r = {100,100,100,100};

    float x = 0.0f;
    float y = 0.0f;

    while (running)
    {
        now = SDL_GetTicks();
        delta = now - oldTime;
        LSD("Delta", delta / 1000.0f);
        c += 0.01;

        /* Poll for and process events */
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q)
            {
                /*SDL_Quit();*/
                break;
                // End the loop.
            }
        } // End Event Checks

        /*while (lag >= MS_PER_UPDATE)*/
        /*{*/
            /*update(delta);*/
            /*lag -= MS_PER_UPDATE;*/
        /*}*/

        for (int i = 0; i < 1000; i++) {
            int a = 2;
            a = a * a;
        }

        float speed = 0.01f;

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0,100,200,100);
        SDL_RenderFillRect(renderer, &r);

        SDL_SetRenderDrawColor(renderer, 0,0,0,100);
        render();
        SDL_RenderPresent(renderer);

        oldTime = now;

    }




    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
