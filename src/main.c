
#include "ecs/ecs.h"

#include "functions/genericsHeader.h"
#include "game/gameGenerics.h"

#include "utils/logging.h"

#include "utils/math/MMath.h"

#include <stdio.h>
#include <stdlib.h>

// gives a variable with name path

void test(Entity e)
{
    e->components.window = malloc(sizeof(Comp_Window));
}

int main(int argc, char *argv[])
{
    logInfo(printf("Starting Engine"), 2);
    ECSContainer container;
    container = malloc(sizeof(ECSContainer));

    StartECS(container);
    // Entity e = CreateEntity(container);
    Entity window = CreateWindowComponent(container, 500, 500);
    container->engineEntities->windowIndex = 0;

    logInfo(printf("Configuration complete, passing to main loop"), 2);
    Start(container, window);

    printf("%i\n", container->entitiesPointer);

    while (0 == 0)
    {
        // Clear SDL Render
        SDL_RenderClear(window->components.window->window_renderer);
        UpdateECS(container, window);

        Update();
    }

    return 0;
}
