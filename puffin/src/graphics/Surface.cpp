
#include "core/Core.h"
#include "math/vector.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "components/Sprite.h"
#include "core/Logging.h"
#include "Surface.h"
#include <string>

namespace pn
{
    namespace graphics
    {
        SDL_Surface *CreateSurfaceFromImage(std::string path)
        {
            SDL_Surface *surface = IMG_Load(path.c_str());

            if (surface == NULL)
            {
                PN_CORE_FATAL("Texture path is invalid");
                printf("%s\n", SDL_GetError());
            }

            return surface;
        }

        void PutPixelSurface(SDL_Surface *surface, int x, int y, SDL_Color rgb)
        {
            Uint32 color = SDL_MapRGB(surface->format, rgb.r, rgb.g, rgb.b);
            Uint32 *const target_pixel = (Uint32 *)((Uint8 *)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel);
            *target_pixel = color;
        }

        void PutPixelSurface(SDL_Surface *surface, int x, int y, Uint32 rgb)
        {
            // Uint32 color = SDL_MapRGB(surface->format, rgb.r, rgb.g, rgb.b);
            Uint32 *const target_pixel = (Uint32 *)((Uint8 *)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel);
            *target_pixel = rgb;
        }

        Uint32 *GetPixel(SDL_Surface *surface, int x, int y)
        {
            Uint32 *const target_pixel = (Uint32 *)((Uint8 *)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel);

            return target_pixel;
        }

        SDL_Color GetPixelColor(SDL_Surface *surface, int x, int y)
        {
            Uint8 *pixels = (Uint8 *)surface->pixels;

            SDL_Color color;

            color.r = pixels[((y * surface->w) + x)];
            color.g = pixels[((y * surface->w) + x)];
            color.b = pixels[((y * surface->w) + x)];

            return color;
        }
    } // namespace graphics

} // namespace pn
