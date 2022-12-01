
#include "../../data/ecs.h"
#include "../../utils/logging.h"
#include "../genericsHeader.h"
#include "../../components/componentsGenarics.h"

#include "submod/physics.h"

void movePosition(Entity e, float x, float y)
{
    e->components.transform->position.x += x;
    e->components.transform->position.y += y;
}
void setPosition(Entity e, float x, float y)
{
    e->components.transform->position.x = x;
    e->components.transform->position.y = y;
}

void moveScale(Entity e, float x, float y)
{
    e->components.transform->scale.x += x;
    e->components.transform->scale.y += y;
}
void setScale(Entity e, float x, float y)
{
    e->components.transform->scale.x = x;
    e->components.transform->scale.y = y;
}

void AddTransformComponent(Entity e)
{
    e->components.transform = malloc(sizeof(Comp_Transform));
    memset(e->components.transform, 0, sizeof(Comp_Transform));
    e->components.CompTransformIndex++;
    logTrace(printf("Transform component allocated with address %p", e->components.transform), 1);
}

Entity CreateTransformComponent(ECSContainer container, Entity window)
{
    Entity e = CreateEntity(container);

    if (e == NULL)
    {
        logError(printf("Entity component not created for window"));
    }

    AddTransformComponent(e);
    return e;
}

void AddMovementComponent(Entity e)
{
    e->components.movement = malloc(sizeof(Comp_Movement));
    memset(e->components.movement, 0, sizeof(Comp_Movement));
    e->components.CompMovementIndex++;
    logTrace(printf("movement component allocated with address %p", e->components.movement), 1);

    e->components.movement->speed = 0.1;
    e->components.movement->gravity = 0.1;
    e->components.movement->terminalVelocities.x = 1;
    e->components.movement->terminalVelocities.y = 2;
}
void UpdateMovementComponent(Entity entity, Entity window)
{

    if (window->components.window->keys[SDLK_d] == 1)
    {
        if (entity->components.movement->veloctity.x < entity->components.movement->terminalVelocities.x)
        {
            entity->components.movement->veloctity.x += entity->components.movement->speed;
        }

        entity->components.movement->dPressed = 1;
    }
    else
    {
        if (entity->components.movement->dPressed == 1)
        {
            entity->components.movement->veloctity.x = 0;
            entity->components.movement->dPressed = 0;
        }
    }

    if (window->components.window->keys[SDLK_a] == 1)
    {
        if (entity->components.movement->veloctity.x > -entity->components.movement->terminalVelocities.x)
        {
            entity->components.movement->veloctity.x -= entity->components.movement->speed;
        }

        entity->components.movement->aPressed = 1;
    }
    else
    {
        if (entity->components.movement->aPressed == 1)
        {
            entity->components.movement->veloctity.x = 0;
            entity->components.movement->aPressed = 0;
        }
    }

    if (window->components.window->keys[SDLK_SPACE] == 1)
    {
        if (entity->components.movement->grounded == 1)
        {
            entity->components.movement->veloctity.y = -3;
            movePosition(entity, 0, entity->components.movement->veloctity.y);
        }
    }

    if (window->components.window->keys[SDLK_a] == 0 && window->components.window->keys[SDLK_d] == 0)
    {
        entity->components.movement->veloctity.x = 0;
    }

    for (size_t col = 0; col < entity->components.movement->collisionLength; col++)
    {
        int c = 1;
        // entity->components.movement->collision[col].position.x;

        float l1[2] = {entity->components.transform->position.x, entity->components.transform->position.y};
        float l2[2] = {entity->components.movement->collision[col]->position.x, entity->components.movement->collision[col]->position.y};

        float r1[2] = {entity->components.transform->position.x + entity->components.image->imageSizeX, entity->components.transform->position.y + entity->components.image->imageSizeY};
        float r2[2] = {entity->components.movement->collision[col]->position.x + entity->components.movement->collision[col]->imageScale.x, entity->components.movement->collision[col]->position.y + entity->components.movement->collision[col]->imageScale.y};

        if ((l1[0] > r2[0]) ||
            (r1[0] < l2[0]) ||
            (l1[1] > r2[1]) ||
            (r1[1] < l2[1]))
        {
            c = 0;
        }

        if (c == 0)
        {
            movePosition(entity, entity->components.movement->veloctity.x, entity->components.movement->veloctity.y);
            entity->components.movement->grounded = 0;
            if (entity->components.movement->veloctity.y < entity->components.movement->terminalVelocities.y)
            {
                entity->components.movement->veloctity.y += entity->components.movement->gravity;
            }
        }
        else
        {
            movePosition(entity, entity->components.movement->veloctity.x, 0);
            entity->components.movement->grounded = 1;
            entity->components.movement->veloctity.y = 0;
        }
    }
}

void AddCollisionObject(Entity movement, Entity newCol)
{
    movement->components.movement->collision[movement->components.movement->collisionLength] = newCol->components.transform;
    movement->components.movement->collisionLength++;
}
