
#include "gameGenerics.h"

#include "../engine/data/ecs.h"
#include "../engine/components/componentsGenarics.h"
#include "../engine/func/genericsHeader.h"
#include "../engine/utils/macros.h"
#include "../engine/utils/logging.h"

// 9:14 AM I found this https://www.youtube.com/watch?v=EMZOtHIL7QM
// nice music!

Entity player;
Entity ground;

void Start(ECSContainer container, Entity window, Entity renderer)
{
    /*
    char background[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/test/building.bmp";
    char groundPath[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/test/BottomBuilding.bmp";
    char playerPath[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/test/player.bmp";

    AddLight(renderer, NewVector2(71, 71), 1, 0.92);
    AddLight(renderer, NewVector2(119, 68), 1, 0.97);
    AddLight(renderer, NewVector2(168, 69), 1, 0.98);
    AddLight(renderer, NewVector2(24, 69), 1, 0.95);

    CreateImageComponentRender(container,window, NewVector2(0,0), NewVector2(192, 108), background, renderer);
    player = CreateImageComponentRender(container,window, NewVector2(158,59), NewVector2(21, 36), playerPath, renderer);
    ground = CreateImageComponentRender(container,window, NewVector2(0,95), NewVector2(192, 13), groundPath, renderer);

    AddMovementComponent(player);
    AddCollisionObject(player, ground);
    */

    char background[200] = "C:/Users/Aidan/Documents/OtherUsslessProjects'/Megan-Engine/assets/images/test/building.bmp";
    AddLight(renderer, NewVector2(95, 10), 5, .98);
    CreateImageComponentRender(container, window, NewVector2(0, 0), NewVector2(192, 108), background, renderer);
}

void Update(ECSContainer container, Entity window, Entity renderer)
{
    // UpdateMovementComponent(player, window);
}
