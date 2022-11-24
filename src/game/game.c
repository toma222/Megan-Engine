
#include "gameGenerics.h"

#include "../ecs/ecs.h"
#include "../components/componentsGenarics.h"
#include "../functions/genericsHeader.h"
#include "../utils/macros.h"
#include "../utils/logging.h"

#include "dominoes/dominoes.h"

void Start(ECSContainer container, Entity window)
{
    int d[2] = {0,0};
    MakeDominoe(container, window, d);

    // Image will be rendered with the component update loop
}

void Update(ECSContainer container, Entity window)
{
}
