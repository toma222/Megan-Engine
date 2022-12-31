
#include "Core.h"
#include "Application.h"
#include "Logging.h"

namespace pn
{
    Application::Application()
    {
        m_window = new Window();
        m_context = new Context();

        m_context->InitGraphics();
        m_window->InitWindow();
    }

    void Application::RunApplication()
    {
        bool running = true;
        PN_CORE_TRACE("Starting the main application loop");

        while (running == true)
        {
            m_window->ClearWindow();
            running = m_window->UpdateWindow();
        }

        PN_CORE_INFO("Exit called, goodbye!!!");
    }
} // namespace PN
