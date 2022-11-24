#include "../utils/math/MMath.h"

typedef struct
{
    struct Vector2 position;
    struct Vector2 scale;

} Comp_Transform;

typedef struct
{
    Comp_Transform *sprites[10];
    int spriteLen;

    struct Vector2 cellSize;
    struct Vector2 padding;
    struct Vector2 rootPosition;
} Comp_Alignment;
