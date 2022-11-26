#include "../utils/math/MMath.h"
#include "../ecs/ecs.h"
typedef struct
{
    struct Vector2 position;
    struct Vector2 scale;
    struct Vector2 imageScale;

} Comp_Transform;

typedef struct
{
    Comp_Transform *sprites[10];
    int spriteLen;

    struct Vector2 cellSize;
    struct Vector2 padding;
    struct Vector2 rootPosition;
} Comp_Alignment;

typedef struct
{
    Comp_Transform *collision[10];
    int collisionLength;
    
    struct Vector2 veloctity;
    struct Vector2 terminalVelocities;

    int grounded;
    int aPressed;
    int dPressed;

    float gravity;
    float speed;
    float jumpVelocity;

} Comp_Movement;

typedef struct
{
    int gravity;
} Comp_Physics;
