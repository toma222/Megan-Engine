#pragma once

#include "SDL2/SDL.h"

#include "../data/ecs.h"
#include "../utils/math/MMath.h"

typedef struct
{
    // computer location
    char path[200];

    int defered;

    // SDL configs
    SDL_Texture *texture;

    SDL_Surface *surface;
    SDL_Surface *renderSurface;

    SDL_Rect texture_rect;

    // sync to prefered size
    int imageSizeX;
    int imageSizeY;

    int xSync;
    int ySync;

    int layer;

} Comp_Image;

typedef struct
{
    struct Vector2 position;
    float strength;
    int radiance;
} Light;

typedef struct
{
    Light light[10];
    int lights;

    // Holds one wicked array
    double lightBuffer[192][108];

    Comp_Image *sprite[20];
    int sprites;
} Comp_DeferedRender;
