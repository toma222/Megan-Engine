#pragma once

#include "Core.h"

#include "SDL2/SDL.h"

namespace pn
{
    class Window
    {
    private:
        SDL_Window *m_window;
        SDL_DisplayMode *m_displayMode;
        SDL_Renderer *m_renderer;

        int m_width;
        int m_height;

    public:
        SDL_Renderer *InitWindow();

        bool UpdateWindow();
        void ClearWindow();

        SDL_Renderer *GetRenderer() { return m_renderer; };
        SDL_Window *GetWindow() { return m_window; };

        ~Window();
    };

} // namespace PN
