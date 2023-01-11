
#pragma once

#include "SDL2/SDL.h"

#include <string>
#include <memory>

namespace puffin
{

    class Surface
    {
    private:
        SDL_Surface *m_surface;
        SDL_Rect *m_surfaceRect;

    public:
        // File path to the image to load as a Surface
        // Surface(std::string path);
        Surface(int width, int height);
        Surface(std::string path, int width, int height);
        Surface(SDL_Surface *surface) { m_surface = surface; };

        ~Surface();

        SDL_Surface *get() { return m_surface; };
        SDL_Rect *GetDimensions() { return m_surfaceRect; };

    public:
        void PutPixel(int x, int y, int r, int g, int b);
        void PutPixel(int x, int y, Uint32 color);

        // Does a scaled blit so that you can change the size and such
        void BlitSurface(Surface *from);

        void ConvertSurface(Surface *windowSurface);
    };
    // namespace graphics

} // namespace pn
