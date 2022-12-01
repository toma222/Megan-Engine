
#include "../../../data/ecs.h"
#include "../../../utils/logging.h"
#include "../../genericsHeader.h"
#include "../../../components/componentsGenarics.h"

void AddPhysicsComponent(Entity e)
{
    e->components.physics = malloc(sizeof(Comp_Physics));
    memset(e->components.physics, 0, sizeof(Comp_Physics));
    e->components.CompPhysicsIndex++;
    // logTrace(printf("Physics component allocated with address %p", e->components.physics), 1);
}

Entity CreatePhysicsComponent(ECSContainer container, Entity window)
{
    Entity e = CreateEntity(container);
    AddPhysicsComponent(e);
    return e;
}

void UpdatePhysicsComponent(Entity entity)
{
    // if(PointInSpriteBox(entity, ))
}
