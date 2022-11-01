
#include "ecs/ecs.h"

#include "functions/genericsHeader.h"
#include "game/gameGenerics.h"

#include "utils/logging.h"
#include "utils/math/MMath.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

long long gTime()
{
    struct timeval te;
    gettimeofday(&te, NULL);
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
    return milliseconds;
}

int main(int argc, char *argv[])
{

    long long b = gTime();
    long long over = gTime();

    logInfo(printf("Starting Engine"), 3);
    ECSContainer container;
    container = malloc(sizeof(ECSContainer));
    logTrace(printf("Container for ECS created with pointer at %p", container), 2);

    StartECS(container);
    // Entity e = CreateEntity(container);
    Entity window = CreateWindowComponent(container, windowX, windowY);
    container->engineEntities->windowIndex = 0;
    logTrace(printf("Window for engine created with pointer at %p", window), 2);
    logInfo(printf("Window created and ECS initialized in %lld MS", gTime() - b), 3);

    Start(container, window);
    logInfo(printf("Engine initilized in in %lld MS", gTime() - over), 2);

    int frameLogCount = 0;
    int epoch = 0;
    char status[10] = "Good";
    b = gTime();
    while (0 == 0)
    {
        // Clear SDL Render
        SDL_RenderClear(window->components.window->window_renderer);
        UpdateECS(container, window);

        Update(container, window);
        frameLogCount++;
        if (frameLogCount == 60)
        {
            logInfo(printf("Status: %s | Time: %i | Entities : %i | Epoch: %i", status, (int)(1000 / ((gTime() - b) / 60)), container->entitiesPointer, epoch), 3);
            epoch++;
            b = gTime();
            frameLogCount = 0;
        }
    }

    return 0;
}
