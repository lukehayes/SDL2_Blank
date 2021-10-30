#ifndef GAME_H
#define GAME_H

/**
 * Nice place to store time related information.
 */
typedef struct
{
    double currentTime;
    double previousTime;
    double delta;
    float MS_PER_UPDATE;

} TimeInfo;


void update(float dt)
{
}

void render()
{
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
