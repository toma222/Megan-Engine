

#include "Renderer.h"
#include "Window.h"
#include "Texture.h"

#include "SDL2/SDL.h"

namespace puffin
{
    Renderer::Renderer(Window *window, int index, Uint32 flags)
    {
        // m_renderer = SDL_CreateRender(window.g)
        m_render = SDL_CreateRenderer(window->get(), index, flags);
    }

    Renderer::~Renderer()
    {
    }

    void Renderer::Clear()
    {
        SDL_RenderClear(m_render);
    }

    void Renderer::Copy(Texture *texture)
    {
        SDL_RenderCopy(m_render, texture->get(), NULL, NULL);
    }

    void Renderer::Present()
    {
        SDL_RenderPresent(m_render);
    }

} // namespace pn
