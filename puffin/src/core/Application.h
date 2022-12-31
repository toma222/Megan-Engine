#pragma once

#include "Core.h"
#include "Window.h"
#include "graphics/Context.h"

namespace pn
{
    class Application
    {
    private:
        Context *m_context;
        Window *m_window;
        static Application *s_app;

    public:
        Application();
        ~Application();

        void RunApplication();
    };

} // namespace PN
