
#include "../genericsHeader.h"

#include "../../components/comps_screen.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_timer.h"
#include "SDL2/SDL_mixer.h"

#include "../genericsHeader.h"

#include "../../ecs/ecs.h"

#include "../../utils/logging.h"
#include "../../utils/time.h"

#include <windows.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdbool.h>
#include <math.h>

#define USI unsigned short int

void MakeWindow(Entity entity, int xSize, int ySize)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    TTF_Init();

    entity->components.window->xSize = xSize;
    entity->components.window->ySize = ySize;

    strcpy(entity->components.window->title, "game");

    entity->components.window->window = SDL_CreateWindow(
        entity->components.window->title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        xSize,
        ySize,
        SDL_WINDOW_OPENGL);

    if (entity->components.window->window == NULL)
    {
        logError(printf("SDL could not make window"));
    }

    /* Initialize Audio */
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
    {
        logError(printf("SDL_Mixer not working"));
    }

    /* Sets up the renderer with the SDL_RENDERER_PRESENTVSYNC option because it runs faster with it (I dont know why)*/
    entity->components.window->window_renderer = SDL_CreateRenderer(entity->components.window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void SyncWindow(long prevTime)
{
    long t = current_timestamp() - prevTime;
    long i = 15 - t;

    if (i < 0)
        i = 0;

    SDL_Delay(i);
    return;
}

int RenderWindow(Entity window)
{
    long startTime = current_timestamp();

    SDL_Event e;
    while (SDL_PollEvent(&e) > 0)
    {
        switch (e.type)
        {
        case SDL_QUIT:
            return -1;
            break;
        }
    }

    /* Presents all the changes made to the window and renders them */
    SDL_RenderPresent(window->components.window->window_renderer);
    SDL_UpdateWindowSurface(window->components.window->window);

    /* This function helps keep the frame rate consistant */
    SyncWindow(startTime);

    return 0;
}

void AddWindowComponent(Entity e)
{
    // Allocate the memory for the data
    e->components.window = malloc(sizeof(Comp_Window));
    memset(e->components.window, 0, sizeof(Comp_Window));
    e->components.CompWindowIndex++;
    logTrace(printf("Window component allocated with address %p", e->components.window), 1);
}

Entity CreateWindowComponent(ECSContainer container, int sizeX, int sizeY)
{
    Entity e = CreateEntity(container);
    AddWindowComponent(e);
    MakeWindow(e, sizeX, sizeY);
    logTrace(printf("Window component configured"), 0);
    return e;
}

void UpdateWindowComponent(Entity entity)
{
    if (RenderWindow(entity) != 0)
    {
        exit(0);
    }
}
