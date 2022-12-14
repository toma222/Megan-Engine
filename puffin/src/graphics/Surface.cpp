
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Surface.h"

#include <string>
#include <iostream>

namespace puffin
{
    Surface::Surface(int width, int height)
    {
        m_surface = SDL_CreateRGBSurface(
            SDL_SWSURFACE,
            width, height,          // Sizes
            16,                     // BPP
#if SDL_BYTEORDER == SDL_LIL_ENDIAN /* OpenGL RGBA masks */
            0x000000FF,
            0x0000FF00,
            0x00FF0000,
            0xFF000000);
#else
            0xFF000000,
            0x00FF0000,
            0x0000FF00,
            0x000000FF);
#endif
    }

    Surface::Surface(std::string path, int width, int height)
    {
        m_surface = SDL_LoadBMP(path.c_str());

        //

        if (m_surface == NULL)
            std::cout << "could not load image, please check your file path\n";

        m_surfaceRect = new SDL_Rect;

        m_surfaceRect->h = height;
        m_surfaceRect->w = width;
        m_surfaceRect->x = 0;
        m_surfaceRect->y = 0;
    }

    Surface::~Surface()
    {
        SDL_FreeSurface(m_surface);
    }

    void Surface::PutPixel(int x, int y, int r, int g, int b)
    {
        Uint32 color = SDL_MapRGB(m_surface->format, r, g, b);
        Uint32 *const target_pixel = (Uint32 *)((Uint8 *)m_surface->pixels + y * m_surface->pitch + x * m_surface->format->BytesPerPixel);
        *target_pixel = color;
    }

    void Surface::PutPixel(int x, int y, Uint32 color)
    {
        Uint32 *const target_pixel = (Uint32 *)((Uint8 *)m_surface->pixels + y * m_surface->pitch + x * m_surface->format->BytesPerPixel);
        *target_pixel = color;
    }

    void Surface::BlitSurface(Surface *from)
    {
        SDL_BlitScaled(from->get(), NULL, m_surface, from->GetDimensions());
    }

    void Surface::ConvertSurface(Surface *windowSurface)
    {
        m_surface = SDL_ConvertSurface(m_surface, windowSurface->get()->format, 0);
    }
} // namespace pn
