
#include "gameGenerics.h"

#include "../ecs/ecs.h"
#include "../components/componentsGenarics.h"
#include "../functions/genericsHeader.h"
#include "../utils/macros.h"
#include "../utils/logging.h"

Entity player;

Entity ground;

void Start(ECSContainer container, Entity window, Entity renderer)
{
    char background[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/game/battle/192x108Background.bmp";
    char groundPath[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/game/battle/ground.bmp";
    char playerPath[200] = "/Users/benjaminwilhite/Desktop/ExtraCCRedy/assets/images/game/player.bmp";

    AddLight(renderer, NewVector2(97,38), 1, 0.95);
    AddLight(renderer, NewVector2(33,91), 1, 0.95);
    AddLight(renderer, NewVector2(157,91), 1, 0.95);
    
    CreateImageComponentRender(container,window, NewVector2(0,0), NewVector2(192, 108), background, renderer);
    ground = CreateImageComponentRender(container,window, NewVector2(23, 93), NewVector2(145, 14), groundPath, renderer);

    player = CreateImageComponentRender(container,window, NewVector2(96,0), NewVector2(8, 8), playerPath, renderer);
}

float xVelocity = 0;
float yVelocity = 0;

int aPressed = 0;
int dPressed = 0;

int grounded = 0;
int doubleJump = 1;

void Update(ECSContainer container, Entity window, Entity renderer)
{
    if(window->components.window->keys[SDLK_d] == 1){
        if(xVelocity < 1.5){
            xVelocity += 0.1;
        }

        dPressed = 1;
    }else{
        if(dPressed == 1){
            xVelocity = 0;
            dPressed = 0;
        }
    }

    if(window->components.window->keys[SDLK_a] == 1){
        if(xVelocity > -1.5){
            xVelocity -= 0.1;
        }

        aPressed = 1;
    }else{
        if(aPressed == 1){
            xVelocity = 0;
            aPressed = 0;
        }
    }

    if(window->components.window->keys[SDLK_SPACE] == 1 ){
        if(grounded == 1){
            yVelocity = -3;
            movePosition(player, 0, yVelocity);
        }
    }

    if(window->components.window->keys[SDLK_a] == 0 && window->components.window->keys[SDLK_d] == 0){
        xVelocity = 0;
    }

    if(PointInSpriteBox(player, ground) == 0){
        movePosition(player, xVelocity, yVelocity);
        grounded = 0;
        if(yVelocity < 2){
            yVelocity += 0.1;
        }
    }else{
        movePosition(player, xVelocity, 0);
        grounded = 1;
        yVelocity = 0;
    }
}
