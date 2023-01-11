
#pragma once

#include <memory>
#include <string>

#include "Renderer.h"
#include "Surface.h"

#include "SDL2/SDL.h"

namespace puffin
{

    // Sorry have to forward declare
    class Renderer;

    class Texture
    {
    private:
        SDL_Texture *m_texture;

    public:
        // Make texture from a surface
        Texture(Surface surface);
        Texture(Renderer *render, std::string imagePath);

        ~Texture();

        SDL_Texture *get() { return m_texture; };

        void LoadSurface(Surface surface);
    };

} // namespace pn
