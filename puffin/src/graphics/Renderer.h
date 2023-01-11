
#pragma once

#include "Texture.h"

#include "SDL2/SDL.h"

#include "Window.h"

namespace puffin
{
    // Sorry, I have to forward declare :(
    class Texture;

    class Renderer
    {
    private:
        SDL_Renderer *m_render;

    public:
        Renderer(Window *window, int index, Uint32 flags);
        ~Renderer();

        SDL_Renderer *get() { return m_render; };

        void Clear();
        void Copy(Texture *texture);
        void Present();
    };
} // namespace pn
