#pragma once

#include "../../ecs/ecs.h"
#include "../../components/componentsGenarics.h"
#include "../../functions/genericsHeader.h"
#include "../../utils/macros.h"
#include "../../utils/logging.h"

Entity Alignment;

Entity cards[6];
int cardLength = 0;

// Drag and drop
int holding[6] = {0, 0, 0, 0, 0};
int canHold = 0;
struct Vector2 dragOffset;

void UpdateCards(Entity window)
{
    for (size_t card = 0; card < cardLength; card++)
    {
        if (MouseInSpriteBox(cards[card], window) == 0 && (window->components.window->mouse & SDL_BUTTON_LMASK) != 0 && canHold == 0)
        {
            holding[card] = 1;

            dragOffset.x = cards[card]->components.transform->position.x - window->components.window->mousePositionX;
            dragOffset.y = cards[card]->components.transform->position.y - window->components.window->mousePositionY;

            canHold = 1;
        }

        if (holding[card] == 1)
        {
            setPosition(cards[card], window->components.window->mousePositionX + dragOffset.x, window->components.window->mousePositionY + dragOffset.y);

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
