
#pragma once

#include "Surface.h"

#include "SDL2/SDL.h"

#include <string>

namespace puffin
{
    class Window
    {
    private:
        SDL_Window *m_window;
        Surface *m_windowSurface;

        bool m_RendererCreated;

    public:
        Window(std::string title, int x, int y, int width, int height, Uint32 flags);
        ~Window();

        void UpdateSurface();

        SDL_Window *get() { return m_window; };
        Surface *GetWindowSurface() { return m_windowSurface; };
    };

} // namespace puffin
