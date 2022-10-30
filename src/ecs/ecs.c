
#include <stdlib.h>
#include <string.h>

#include "../utils/logging.h"

#include "../functions/genericsHeader.h"

#include "ecs.h"

void StartECS(ECSContainer container)
{
    container->entitiesPointer = 0;
}

Entity CreateEntity(ECSContainer container)
{
    // Find a place for that in memory
    Entity e = malloc(sizeof(struct Struct_Entity));
    container->entities[container->entitiesPointer] = e;

    // Clean up the place a bit
    memset(e, 0, sizeof(struct Struct_Entity));

    // Gets ready for the next component
    container->entities[container->entitiesPointer]->id = container->entitiesPointer;

    container->entitiesPointer++;

    return e;
}

void DestroyEntity(ECSContainer container, unsigned short int id)
{
    // this cell is now free for more data to be put
    free(container->entities[id]);

    container->entitiesPointer = id;
}

void UpdateECS(ECSContainer container, Entity window)
{
    // loop through all the components
    for (size_t comp = 0; comp < 2; comp++)
    {
        if (container->entities[comp]->components.CompImageIndex == 1)
        {
            RenderSprite(window, container->entities[comp]);
            // UpdateImageComponent(window, container->entities[comp]);
        }
        // if (container->entities[comp]->components.CompWindowIndex == 1)
        //{

        //}
    }

    UpdateWindowComponent(window);
}
