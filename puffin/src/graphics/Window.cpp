
#include "Surface.h"

#include "SDL2/SDL.h"

#include "Window.h"

namespace puffin
{
    Window::Window(std::string title, int x, int y, int width, int height, Uint32 flags)
    {
        m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
        m_windowSurface = new Surface(SDL_GetWindowSurface(m_window));
        m_RendererCreated = false;
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_window);
    }

    void Window::UpdateSurface()
    {
        SDL_UpdateWindowSurface(this->m_window);
    }
} // namespace puffin
