
#include "gameGenerics.h"

#include "../ecs/ecs.h"
#include "../components/componentsGenarics.h"
#include "../functions/genericsHeader.h"
#include "../utils/macros.h"

Entity sprite;

void Start(ECSContainer container, Entity window)
{
    imagePath = "C:/Users/Aidan/Desktop/progectStructureTester/assets/images/test/checkerboard.bmp";
    sprite = CreateImageComponent(container, window, NewVector2(0, 0), NewVector2(16, 16), path);
}

void Update(ECSContainer container, Entity window)
{
    // movePosition(sprite, 1, 0);
}
