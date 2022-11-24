
#include "../../ecs/ecs.h"
#include "../../components/componentsGenarics.h"
#include "../../functions/genericsHeader.h"
#include "../../utils/macros.h"
#include "../../utils/logging.h"

Entity MakeDominoe(ECSContainer container, Entity window, int points[2]){
    char path[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/dominoes/Background.bmp";

    Entity e = CreateImageComponent(
        container, window,
        NewVector2(0, 0), NewVector2(9, 20),
        path
    );

    return e;
}
