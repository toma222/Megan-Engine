
#include "graphics/Window.h"

#include "Core.h"
#include "Application.h"
#include "Logging.h"
#include "LayerStack.h"

namespace pn
{
    Application::Application(WindowProps *props)
    {
        PN_CORE_INFO("Application constructor called");
        m_context = new Context();

        m_appSurface = new AppSurface(props);

        m_layerStack = new LayerStack();
        // m_graphics = new graphics::Graphics();

        m_layerStack->InitLayerStack();
        m_context->InitGraphics();
        // m_graphics->Attach(
        //     m_window->InitWindow());

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
            m_appSurface->ClearWindow();
            m_layerStack->UpdateLayers();
            running = m_appSurface->UpdateWindow();
        }

        m_layerStack->DetachLayers();
        m_layerStack->ClearLayers();

        PN_CORE_INFO("Exit called, goodbye!!!");
    }
} // namespace PN
