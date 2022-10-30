
#pragma once

#include "SDL2/SDL.h"

#include <windows.h>
#include <stdio.h>

typedef struct
{
    int xSize;
    int ySize;
    char title[20];
    SDL_Window *window;
    SDL_Renderer *window_renderer;
} Comp_Window;
