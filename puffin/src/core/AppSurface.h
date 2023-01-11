
#pragma once

#include "core/Core.h"
#include "graphics/Window.h"

#include <string>

namespace puffin
{
    typedef class
    {
    public:
        std::string name;
        int width;
        int height;
        bool fullScreen;
    } WindowProps;

    class AppSurface
    {
    private:
        Window *m_window;
        WindowProps *m_props;

    public:
        AppSurface(WindowProps *props);
        ~AppSurface();

        Window *GetWindow() { return m_window; };

        bool UpdateWindow();
        void ClearWindow();
        // void InitWindow();
    };
} // namespace puffin
