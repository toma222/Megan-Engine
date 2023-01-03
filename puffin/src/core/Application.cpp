
#include "Core.h"
#include "Application.h"
#include "Logging.h"
#include "LayerStack.h"

namespace pn
{
    Application::Application()
    {
        PN_CORE_INFO("Application constructor called");
        m_window = new Window();
        m_context = new Context();
        m_layerStack = new LayerStack();
        m_graphics = new graphics::Graphics();

        m_layerStack->InitLayerStack();
        m_context->InitGraphics();
        m_graphics->Attach(
            m_window->InitWindow());

        Application::s_app = this;
    }

    void Application::RunApplication()
    {
        bool running = true;

        m_layerStack->AttachLayers();

        PN_CORE_TRACE("Starting the main application loop, you are good to go!");
        m_layerStack->UpdateLayers();

        while (running == true)
        {
            m_window->ClearWindow();
            m_layerStack->UpdateLayers();
            running = m_window->UpdateWindow();
        }

        m_layerStack->DetachLayers();
        m_layerStack->ClearLayers();

        PN_CORE_INFO("Exit called, goodbye!!!");
    }
} // namespace PN
