
#include <stdlib.h>
#include <string.h>

#include "../utils/logging.h"

#include "../func/genericsHeader.h"

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

    memset(e, 0, sizeof(struct Struct_Entity));

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

void UpdateECS(ECSContainer container, Entity window, Entity renderer)
{
    // loop through all the components
    for (size_t comp = 0; comp < container->entitiesPointer; comp++)
    {
        /*
        if (container->entities[comp]->components.CompPhysicsIndex == 1){
            // Update the position

        }
        */

        if (container->entities[comp]->components.CompImageIndex == 1)
        {
            RenderSprite(window, container->entities[comp]);
            UpdateImageComponent(window, container->entities[comp]);

            if (container->entities[comp]->components.image->defered == 1)
            {
                DeferedRenderSprite(container->entities[comp], renderer, window);
            }
        }
    }

    UpdateWindowComponent(window);
}
