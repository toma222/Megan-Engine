
#include "Core.h"
#include "Logging.h"
#include "Window.h"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"
#include "SDL2/SDL.h"

namespace pn
{
    SDL_Renderer *Window::InitWindow()
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

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        return m_renderer;
    }

    bool Window::UpdateWindow()
    {

        SDL_Event e;

        SDL_RenderPresent(m_renderer);

        while (SDL_PollEvent(&e))
        {
            ImGui_ImplSDL2_ProcessEvent(&e);

            if (e.type == SDL_QUIT)
                return false;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
                return false;
        }

        return true;
    }

    void Window::ClearWindow()
    {
        SDL_RenderClear(m_renderer);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_window);
    }
} // namespace PN
