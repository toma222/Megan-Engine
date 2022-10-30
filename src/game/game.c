
#include "gameGenerics.h"

#include "../ecs/ecs.h"
#include "../components/componentsGenarics.h"
#include "../functions/genericsHeader.h"
#include "../utils/macros.h"

void Start(ECSContainer container, Entity window)
{
    imagePath = "C:/Users/Aidan/Desktop/progectStructureTester/assets/images/test/checkerboard.bmp";
    Entity sprite = CreateImageComponent(container, window, NewVector2(0, 0), NewVector2(100, 100), path);
}

void Update(ECSContainer container, Entity window)
{
}
