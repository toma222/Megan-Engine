
#pragma once

#include "SDL2/SDL.h"
#include "../utils/math/MMath.h"

#include <stdio.h>

typedef struct
{
    int xSize;
    int ySize;
    char title[20];
    SDL_Window *window;
    SDL_Renderer *window_renderer;
    struct Vector2 sync;

    int mousePositionX;
    int mousePositionY;

    int keys[322];

    Uint32 mouse;
} Comp_Window;
