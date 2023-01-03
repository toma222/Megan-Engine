
#include "core/Core.h"
#include "math/vector.h"
#include "SDL2/SDL.h"
#include "components/Sprite.h"
#include "core/Application.h"
#include "core/Logging.h"
#include "Texture.h"

namespace pn
{
    namespace graphics
    {
        SDL_Texture *CreateTextureFromSurface(SDL_Surface *surf)
        {
            SDL_Texture *texture = SDL_CreateTextureFromSurface(Application::Get()->GetWindow()->GetRenderer(), surf);

            if (texture == NULL)
            {
                PN_CORE_FATAL("Could not create texture");
                printf("%s\n", SDL_GetError());
            }

            return texture;
        }

        // @deprecated this WILL crash yor program. Going to fix it later
        void PutPixel(SDL_Texture *texture)
        {
            Uint32 *pixels = nullptr;
            int pitch = 0;
            Uint32 format;

            // Get the size of the texture.
            int w, h;
            SDL_QueryTexture(texture, &format, nullptr, &w, &h);

            // Now let's make our "pixels" pointer point to the texture data.
            if (SDL_LockTexture(texture, nullptr, (void **)&pixels, &pitch))
            {
                // If the locking fails, you might want to handle it somehow. SDL_GetError(); or something here.
                PN_CORE_FATAL("Texture Locking failed");
                printf(SDL_GetError());
            }

            SDL_PixelFormat pixelFormat;
            pixelFormat.format = format;
            // Now you want to format the color to a correct format that SDL can use.
            // Basically we convert our RGB color to a hex-like BGR color.
            Uint32 color = SDL_MapRGB(&pixelFormat, 0, 0, 0);

            // Before setting the color, we need to know where we have to place it.
            Uint32 pixelPosition = 0 * (pitch / sizeof(unsigned int)) + 0;

            // Now we can set the pixel(s) we want.
            pixels[pixelPosition] = color;

            // Also don't forget to unlock your texture once you're done.
            SDL_UnlockTexture(texture);
        }
    }
} // namespace pn
