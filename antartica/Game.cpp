
#include <puffin.h>
#include "GameLayer/GameLayer.h"
// #include "GameLayer/ImguiLayer.h"

#include <memory>

puffin::Application *WakeEngine()
{
    puffin::WindowProps *props = new puffin::WindowProps();
    props->name = "hello";
    props->height = 500;
    props->width = 500;

    puffin::container = new puffin::Container(10);
    puffin::Application *app = new puffin::Application(props);

    app->GetLayerStack()->AddLayer<GameLayer>();
    // app->GetLayerStack()->AddLayer<ImguiLayer>();

    return app;
}
