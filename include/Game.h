#ifndef GAME_H
#define GAME_H

void update(float dt)
{
    printf("Delta: %f \n", dt);
}


void render()
{
    printf("Rendering \n");
}

void processInput()
{
    /* Poll for and process events */
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q)
        {
            SDL_Quit();
            // End the loop.
        }
    } // End Event Checks
}

#endif
