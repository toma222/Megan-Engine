
#include <puffin.h>
#include "GameLayer/GameLayer.h"
#include "GameLayer/ImguiLayer.h"

#include <memory>

puffin::Application *WakeEngine()
{
    puffin::container = new puffin::Container(10);
    puffin::Application *app = new puffin::Application();

    app->GetLayerStack()->AddLayer<GameLayer>();
    // app->GetLayerStack()->AddLayer<ImguiLayer>();

    return app;
}
