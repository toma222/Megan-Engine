
#include "Core.h"
#include "Logging.h"
#include "Window.h"

#include "SDL2/SDL.h"

namespace pn
{
    void Window::InitWindow()
    {
        PN_CORE_TRACE("Creating the window");
        SDL_DisplayMode DM;
        SDL_GetCurrentDisplayMode(0, &DM);
        auto Width = DM.w;
        auto Height = DM.h;

        m_window = SDL_CreateWindow("Game",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    Width,
                                    Height,
                                    0);

        m_height = Height;
        m_width = Width;

        /* Checks if window has been created; if not, exits program */
        if (m_window == NULL)
        {
            PN_CORE_FATAL("SDL window not created");
        }
    }

    bool Window::UpdateWindow()
    {

        SDL_Event e;

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                return false;
        }

        return true;
    }

    void Window::ClearWindow()
    {
        SDL_UpdateWindowSurface(m_window);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_window);
    }
} // namespace PN
