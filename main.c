#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "Game.h"

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



    static double limitFPS = 1.0 / 60.0;
    double lastTime = SDL_GetPerformanceCounter(), timer = lastTime;
    double deltaTime = 0, nowTime = 0;
    int frames = 0 , updates = 0;

    // - While window is alive
    while (true)
    {
        /* Poll for and process events */
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q)
            {
                // End the loop.
                break;
            }
        } // End Event Checks

        // - Measure time
        nowTime = SDL_GetPerformanceCounter();
        deltaTime += (nowTime - lastTime) / limitFPS;
        lastTime = nowTime;

        // - Only update at 60 frames / s
        while (deltaTime >= 1.0){
            //update();   // - Update function

            updates++;
            deltaTime--;
        }

        // - Render at maximum possible frames

        SDL_RenderClear(renderer);
        //render(); // - Render function
        SDL_RenderPresent(renderer);


        frames++;


        // - Reset after one second
        if (SDL_GetPerformanceCounter() - timer > 1.0) {
            timer ++;
            printf("FPS: %i. Updates: %i \n", frames, updates);
            updates = 0, frames = 0;
        }

    }
}

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

return 0;
}
