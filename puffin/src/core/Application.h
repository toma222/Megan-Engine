#pragma once

#include "Core.h"
#include "graphics/Window.h"
#include "graphics/Context.h"
#include "graphics/Graphics.h"
#include "AppSurface.h"
#include "LayerStack.h"

namespace pn
{
    class Application
    {
    private:
        Context *m_context;
        AppSurface *m_appSurface;
        // graphics::Graphics *m_graphics;
        LayerStack *m_layerStack;

    public:
        static Application *s_app;

    public:
        Application(WindowProps *props);
        ~Application();

        void RunApplication();

        static Application *Get() { return s_app; };

        LayerStack *GetLayerStack() { return m_layerStack; };
        Window *GetWindow() { return m_appSurface->GetWindow(); };
        Context *GetContext() { return m_context; };
        // graphics::Graphics *GetGraphics() { return m_graphics; };
    };

} // namespace PN
