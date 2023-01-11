
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Texture.h"
#include "Renderer.h"

#include <iostream>

namespace puffin
{

    Texture::Texture(Surface surface)
    {
        // SDL_CreateTextureFromSurface(surface.GetSDLSurface());
    }

    Texture::Texture(Renderer *renderer, std::string imagePath)
    {
        SDL_Surface *surface = IMG_Load(imagePath.c_str());

        if (surface == NULL)
            std::cout << "could not load surface\n";

        m_texture = SDL_CreateTextureFromSurface(renderer->get(), surface);

        SDL_FreeSurface(surface);
    }

    Texture::~Texture()
    {
    }

    void LoadSurface(Surface surface)
    {
    }

} // namespace pn
