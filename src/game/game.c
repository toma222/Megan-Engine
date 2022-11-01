
#include "gameGenerics.h"

#include "../ecs/ecs.h"
#include "../components/componentsGenarics.h"
#include "../functions/genericsHeader.h"
#include "../utils/macros.h"

//Entity sprite;

void Start(ECSContainer container, Entity window)
{
    imagePath = "D:/progectStructureTester/assets/images/test/checkerboard.bmp";

    Entity sprite1 = CreateImageComponent(container, window, NewVector2(0, 0), NewVector2(16, 16), path);
    Entity sprite2 = CreateImageComponent(container, window, NewVector2(0, 0), NewVector2(16, 16), path);
    Entity sprite3 = CreateImageComponent(container, window, NewVector2(0, 0), NewVector2(16, 16), path);

    Entity a = CreateAlignmentComponent(container, NewVector2(16,0), NewVector2(10,0));
    AddImageToAlignment(a,sprite1);
    AddImageToAlignment(a,sprite2);
    AddImageToAlignment(a,sprite3);

    CalculateAlignmentPosition(a);
}

void Update(ECSContainer container, Entity window)
{
    // movePosition(sprite, 1, 0);
}
