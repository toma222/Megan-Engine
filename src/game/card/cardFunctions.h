#pragma once

#include "../../ecs/ecs.h"
#include "../../components/componentsGenarics.h"
#include "../../functions/genericsHeader.h"
#include "../../utils/macros.h"
#include "../../utils/logging.h"

Entity cards[6];
int cardLength = 0;

Entity Alignment;

int holding[6] = {0, 0, 0, 0, 0};
int canHold = 0;

void UpdateCards(Entity window)
{
    for (size_t card = 0; card < cardLength; card++)
    {
        if (MouseInSpriteBox(cards[card], window) == 0 && (window->components.window->mouse & SDL_BUTTON_LMASK) != 0 && canHold == 0)
        {
            holding[card] = 1;
            canHold = 1;
        }

        if (holding[card] == 1)
        {
            setPosition(cards[card], window->components.window->mousePositionX, window->components.window->mousePositionY);

            if ((window->components.window->mouse & SDL_BUTTON_LMASK) == 0)
            {
                holding[card] = 0;
                canHold = 0;
                CalculateAlignmentPosition(Alignment);
            }
        }
    }
}

void InitCards(ECSContainer container)
{
    Alignment = CreateAlignmentComponent(container, NewVector2(25, 0), NewVector2(4, 0), NewVector2(11, 63));
}

void AddCard(ECSContainer container, char location[200])
{
    cards[cardLength] = CreateImageComponent(container, container->entities[0], NewVector2(10, 63), NewVector2(25, 35), location);
    AddImageToAlignment(Alignment, cards[cardLength]);
    cardLength++;

    CalculateAlignmentPosition(Alignment);
}
