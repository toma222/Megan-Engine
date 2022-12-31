#pragma once

#include "Application.h"

extern puffin::Application *WakeEngine();

int main(int argc, char *argv[])
{
    puffin::Application *app = WakeEngine();

    app->RunApplication();

    return 0;
}