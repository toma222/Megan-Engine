
#include "gameGenerics.h"

#include "../ecs/ecs.h"
#include "../components/componentsGenarics.h"
#include "../functions/genericsHeader.h"
#include "../utils/macros.h"
#include "../utils/logging.h"

// Entity sprite;

void Start(ECSContainer container, Entity window)
{

    // Background
    char path[200] = "C:/Users/Aidan/Desktop/progectStructureTester/assets/images/game/battle/Untitled.bmp";
    CreateImageComponent(container, window, NewVector2(0, 0), NewVector2(192, 108), path);

    // Player Card
    char playerCardPath[200] = "C:/Users/Aidan/Desktop/progectStructureTester/assets/images/game/PlayerCard.bmp";
    CreateImageComponent(container, window, NewVector2(143, 1), NewVector2(40, 55), playerCardPath);

    // Test card
    char cardPath[200] = "C:/Users/Aidan/Desktop/progectStructureTester/assets/images/game/battle/cards/Kick.bmp";
    // Entity alignment = CreateAlignmentComponent()
    CreateImageComponent(container, window, NewVector2(10, 63), NewVector2(25, 35), cardPath);
}

void Update(ECSContainer container, Entity window)
{
}
