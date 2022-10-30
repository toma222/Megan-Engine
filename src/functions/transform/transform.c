
#include "../../ecs/ecs.h"
#include "../../utils/logging.h"
#include "../genericsHeader.h"
#include "../../components/componentsGenarics.h"

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