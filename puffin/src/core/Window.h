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

        int m_width;
        int m_height;

    public:
        void InitWindow();
        bool UpdateWindow();
        void ClearWindow();

        ~Window();
    };
} // namespace PN
