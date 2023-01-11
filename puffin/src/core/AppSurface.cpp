
#include "graphics/Window.h"

#include "AppSurface.h"

namespace puffin
{
    AppSurface::AppSurface(WindowProps *props)
    {
        // make an SDL window with our brand new shiny abstraction
        m_props = props;

        // flags are a tomorrow problem
        if (props->fullScreen == true)
        {
            m_window = new Window(props->name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, props->width, props->height, SDL_WINDOW_FULLSCREEN);
        }
        else
        {
            m_window = new Window(props->name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, props->width, props->height, 0);
        }
    }

    bool AppSurface::UpdateWindow()
    {

        SDL_Event e;
        while (SDL_PollEvent(&e) > 0)
        {
            switch (e.type)
            {
            case SDL_QUIT:
                return false;
                break;
            case SDL_KEYDOWN:
                return false;
                break;
            }

            m_window->UpdateSurface();
        }

        return true;
    }

    void AppSurface::ClearWindow()
    {
        // clear
    }
} // namespace puffin
