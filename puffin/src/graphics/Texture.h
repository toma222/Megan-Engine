
#pragma once

#include "core/Core.h"
#include "math/vector.h"
#include "SDL2/SDL.h"
#include "components/Sprite.h"

namespace pn
{
    namespace graphics
    {
        SDL_Texture *CreateTextureFromSurface(SDL_Surface *surf);

        void PutPixel(SDL_Texture *texture);

    }
} // namespace pn
