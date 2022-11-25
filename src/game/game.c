
#include "gameGenerics.h"

#include "../ecs/ecs.h"
#include "../components/componentsGenarics.h"
#include "../functions/genericsHeader.h"
#include "../utils/macros.h"
#include "../utils/logging.h"

Entity sprite;

void Start(ECSContainer container, Entity window, Entity renderer)
{
    char path[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/test/192x108.bmp";
    // Entity e = CreateImageComponentRender(container, window, NewVector2(0, 0), NewVector2(32,32), path);
    

    AddLight(renderer, NewVector2(10,10), 1, 0.95);
    AddLight(renderer, NewVector2(30,30), 1, 0.8);

    
    sprite = CreateImageComponentRender(container,window, NewVector2(0,0), NewVector2(32, 32), path, renderer);
}

void Update(ECSContainer container, Entity window, Entity renderer)
{
    
}
