

#include "core/Core.h"
#include "core/Logging.h"
#include "Context.h"

#include <SDL2/SDL.h>
#include <cstdio>

namespace pn
{
    void Context::InitGraphics()
    {
        PN_CORE_TRACE("Waking up SDL");
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
        }
    }
} // namespace PN