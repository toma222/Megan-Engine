
#include "gameGenerics.h"

#include "../ecs/ecs.h"
#include "../components/componentsGenarics.h"
#include "../functions/genericsHeader.h"
#include "../utils/macros.h"
#include "../utils/logging.h"

// 9:14 AM I found this https://www.youtube.com/watch?v=EMZOtHIL7QM
// nice music!

Entity player;
Entity ground;

void Start(ECSContainer container, Entity window, Entity renderer)
{
    char background[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/game/battle/192x108Background.bmp";
    char groundPath[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/game/battle/ground.bmp";
    char playerPath[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/game/player.bmp";

    AddLight(renderer, NewVector2(97,38), 1, 0.95);
    AddLight(renderer, NewVector2(33,91), 1, 0.95);
    AddLight(renderer, NewVector2(157,91), 1, 0.95);
    
    CreateImageComponentRender(container,window, NewVector2(0,0), NewVector2(192, 108), background, renderer);
    player = CreateImageComponentRender(container,window, NewVector2(96,0), NewVector2(8, 8), playerPath, renderer);
    ground = CreateImageComponentRender(container,window, NewVector2(23, 93), NewVector2(145, 14), groundPath, renderer);
    
    AddMovementComponent(player);
    AddCollisionObject(player, ground);
}

void Update(ECSContainer container, Entity window, Entity renderer)
{
    UpdateMovementComponent(player, window);
}
