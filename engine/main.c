
#include "data/ecs.h"

#include "func/genericsHeader.h"
#include "../game/gameGenerics.h"

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

    logProccess(printf("Creating entity component system"), 0);
    ECSContainer container;
    container = malloc(sizeof(ECSContainer) * 502);
    logComplete(printf("Container for ECS created with pointer at %p", container), 1);

    StartECS(container);

    Entity window = CreateWindowComponent(container, windowX, windowY);

    Entity renderer = CreateDeferedRenderComponent(container, window);

    over = gTime();
    Start(container, window, renderer);
    logInfo(printf("Engine initialized in in %lld MS", gTime() - over), 2);

    int frameLogCount = 0;
    int epoch = 0;
    char status[10] = "Good";
    b = gTime();

    while (0 == 0)
    {
        // Clear SDL Render
        SDL_RenderClear(window->components.window->window_renderer);
        UpdateECS(container, window, renderer);

        Update(container, window, renderer);
        frameLogCount++;
        if (frameLogCount == 60)
        {
            logInfo(printf("Status: %s | Time: %i MS | Entities : %i | Epoch: %i", status, (int)((gTime() - b) / 60), container->entitiesPointer, epoch), 3);
            epoch++;
            b = gTime();
            frameLogCount = 0;
        }
    }

    return 0;
}
