#pragma once

#include "Core.h"
#include "Window.h"
#include "graphics/Context.h"
#include "graphics/Graphics.h"
#include "LayerStack.h"

namespace pn
{
    class Application
    {
    private:
        Context *m_context;
        Window *m_window;
        graphics::Graphics *m_graphics;
        LayerStack *m_layerStack;

    public:
        static Application *s_app;

    public:
        Application();
        ~Application();

        void RunApplication();

        static Application *Get() { return s_app; };

        LayerStack *GetLayerStack() { return m_layerStack; };
        Window *GetWindow() { return m_window; };
        Context *GetContext() { return m_context; };
        graphics::Graphics *GetGraphics() { return m_graphics; };
    };

} // namespace PN
