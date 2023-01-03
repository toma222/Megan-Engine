#pragma once

#include "Application.h"
#include "Container.h"

extern puffin::Application *WakeEngine();

int main(int argc, char *argv[])
{
    PN_CORE_INFO("main called");

    puffin::Application *app = WakeEngine();

    app->RunApplication();

    return 0;
}

puffin::Application *puffin::Application::s_app;
