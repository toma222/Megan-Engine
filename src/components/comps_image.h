
#include "SDL2/SDL.h"

typedef struct
{
    // computer location
    char path[200];

    // SDL configs
    SDL_Texture *texture;
    SDL_Rect texture_rect;

    // sync to prefered size
    int imageSizeX;
    int imageSizeY;

    int xSync;
    int ySync;

    int layer;

} Comp_Image;
