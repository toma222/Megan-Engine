
#pragma once

#include "comps_screen.h"
#include "comps_image.h"
#include "comps_transform.h"

#include "../ecs/ecs.h"

// Holds every instance of every component
struct Components
{
    int *update;

    Comp_Window *window;
    int CompWindowIndex;

    Comp_Image *image;
    int CompImageIndex;

    Comp_Transform *transform;
    int CompTransformIndex;

    Comp_Alignment *alignment;
    int CompAlignmentIndex;
};

/*
struct Component_Tracker
{
    int windowCounter;
    int windowIndex[];

    int imageCounter;
    int imageIndex[];

    int transformCounter;
    int transformIndex[];
}
*/