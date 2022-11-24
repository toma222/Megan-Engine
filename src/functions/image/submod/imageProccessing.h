
#include "../../../ecs/ecs.h"
#include "../../../utils/logging.h"
#include "../../genericsHeader.h"

#include "../../../utils/math/MMath.h"
#include "../../../utils/macros.h"

void PutPixel(SDL_Surface *image, int x, int y, Uint32 color)
{

    Uint32 *const target_pixel = (Uint32 *)((Uint8 *)image->pixels + x * image->pitch + y * image->format->BytesPerPixel);
    *target_pixel = color;
}

void InitImageProcessing(Comp_Image *sprite)
{
    return;
}

void RenderTextureFromSurface(Comp_Image *sprite, Comp_Window *window)
{
    sprite->texture = SDL_CreateTextureFromSurface(window->window_renderer, sprite->surface);

    if (SDL_RenderCopy(window->window_renderer, sprite->texture, NULL, &sprite->texture_rect) < 0)
    {
        SDL_GetError();
        logError(printf(" %s", SDL_GetError()));
    }
    else
    {
        logTrace(printf("Sprite Successfully Drawn"), 0);
    }
}

void RenderSurfaceFromImage(Comp_Image *sprite, Comp_Window *window)
{

    /* Loads the image in and makes it a texture */
    SDL_Surface *image = SDL_LoadBMP(sprite->path);
    if (image == NULL)
    {
        logWarning(printf("Could not find %s", sprite->path), 2);
    }
    else
    {
        sprite->surface = image;
    }
}

Entity CreateImageComponentProcessing(ECSContainer container, Entity window, struct Vector2 position, struct Vector2 imageScale, char path[200])
{
    Entity e = CreateEntity(container);
    AddImageComponent(e);
    AddTransformComponent(e);

    e->components.transform->position.x = position.x;
    e->components.transform->position.y = position.y;

    e->components.transform->scale.x = 1;
    e->components.transform->scale.y = 1;

    e->components.image->imageSizeX = imageScale.x;
    e->components.image->imageSizeY = imageScale.y;

    strcpy(e->components.image->path, path);
    MakeSprite(window, e);
    RenderSurfaceFromImage(e->components.image, window->components.window);
    InitImageProcessing(e->components.image);
    RenderTextureFromSurface(e->components.image, window->components.window);

    return e;
}

Entity CreateImageComponentProcessingBlank(ECSContainer container, Entity window, struct Vector2 position, struct Vector2 imageScale)
{
    Entity e = CreateEntity(container);
    AddImageComponent(e);
    AddTransformComponent(e);

    e->components.transform->position.x = position.x;
    e->components.transform->position.y = position.y;

    e->components.transform->scale.x = 1;
    e->components.transform->scale.y = 1;

    e->components.image->imageSizeX = imageScale.x;
    e->components.image->imageSizeY = imageScale.y;

    MakeSprite(window, e);
    // RenderSurfaceFromImage(e->components.image, window->components.window);
    e->components.image->surface = SDL_CreateRGBSurface(0, imageScale.x, imageScale.y, 0, 0, 0, 0, 0);
    RenderTextureFromSurface(e->components.image, window->components.window);

    return e;
}