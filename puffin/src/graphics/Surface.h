
#pragma once

#include "core/Core.h"
#include "math/vector.h"
#include "SDL2/SDL.h"
#include "components/Sprite.h"
#include <string>

namespace pn
{
    namespace graphics
    {
        SDL_Surface *CreateSurfaceFromImage(std::string path);

        void PutPixelSurface(SDL_Surface *surf, int x, int y, SDL_Color rgb);
        void PutPixelSurface(SDL_Surface *surf, int x, int y, Uint32 rgb);

        Uint32 *GetPixel(SDL_Surface *texture, int x, int y);
        SDL_Color GetPixelColor(SDL_Surface *texture, int x, int y);
    } // namespace graphics

} // namespace pn
