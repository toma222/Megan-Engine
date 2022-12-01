
#include "../../../data/ecs.h"
#include "../../../utils/logging.h"
#include "../../genericsHeader.h"

#include "../../../utils/math/MMath.h"
#include "../../../../game/settings.h"

void AddAlignmentComponent(Entity e)
{
    e->components.alignment = malloc(sizeof(Comp_Alignment));
    memset(e->components.alignment, 0, sizeof(Comp_Alignment));
    e->components.CompAlignmentIndex = 1;
    logTrace(printf("Alignment component allocated with address %p", e->components.alignment), 1);
}

Entity CreateAlignmentComponent(ECSContainer container, struct Vector2 cellSize, struct Vector2 cellPadding, struct Vector2 rootPosition)
{
    Entity e = CreateEntity(container);
    AddAlignmentComponent(e);

    e->components.alignment->cellSize = cellSize;
    e->components.alignment->padding = cellPadding;
    e->components.alignment->rootPosition = rootPosition;

    return e;
}

void CalculateAlignmentPosition(Entity alignment)
{
    for (int i = 0; i < alignment->components.alignment->spriteLen; i++)
    {
        alignment->components.alignment->sprites[i]->position.x = (i * (alignment->components.alignment->cellSize.x + alignment->components.alignment->padding.x)) + alignment->components.alignment->rootPosition.x;
        alignment->components.alignment->sprites[i]->position.y = (i * (alignment->components.alignment->cellSize.y + alignment->components.alignment->padding.y)) + alignment->components.alignment->rootPosition.y;
    }
}

void AddImageToAlignment(Entity alignment, Entity sprite)
{
    alignment->components.alignment->sprites[alignment->components.alignment->spriteLen] = sprite->components.transform;
    alignment->components.alignment->spriteLen++;
}

void UpdateAlignmentComponent(Entity alignment)
{
    // overrides transform components
    /*
    for(int i = 0; i < alignment->components.alignment->spriteLen; i++){
        alignment->components.alignment->sprites[i]->position.x = 100;
        alignment->components.alignment->sprites[i]->position.y = 100;
    }
    */
}
