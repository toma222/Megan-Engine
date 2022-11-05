
#include "../../ecs/ecs.h"
#include "../../utils/logging.h"
#include "../genericsHeader.h"
#include "../../components/componentsGenarics.h"

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
    AddTransformComponent(e);
    return e;
}

void UpdateTransformComponent(Entity entity)
{
}