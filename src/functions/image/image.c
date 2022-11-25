
#define PROJECT_ROOT_PATH "C:/Users/Aidan/Documents/OtherUsslessProjects'/Megan/"

#include "../../ecs/ecs.h"
#include "../../utils/logging.h"
#include "../genericsHeader.h"

#include "../../utils/math/MMath.h"
#include "../../utils/macros.h"

#include "SDL2/SDL_ttf.h"

#include "submod/alignment.h"
#include "submod/rendering.h"

void RenderSprite(Entity window, Entity sprite)
{
    /* Calculates position based on the sync values */
    sprite->components.image->texture_rect.x = (sprite->components.transform->position.x * sprite->components.image->xSync);
    sprite->components.image->texture_rect.y = (sprite->components.transform->position.y * sprite->components.image->ySync);

    /*
        The scale uses relative units from the user
        pixels*pixels is multiplied by size*size
        so that a scale of 1,1 would be the native image size
    */
    sprite->components.image->texture_rect.w = sprite->components.transform->scale.x * sprite->components.image->imageSizeX * sprite->components.image->xSync;
    sprite->components.image->texture_rect.h = sprite->components.transform->scale.y * sprite->components.image->imageSizeY * sprite->components.image->ySync;

    if (SDL_RenderCopy(window->components.window->window_renderer, sprite->components.image->texture, NULL, &sprite->components.image->texture_rect) != 0)
    {
        // logError(printf("%s", SDL_GetError()));
    }
}

void RenderTextureFromImage(Comp_Image *sprite, Comp_Window *window)
{
    /* Loads the image in and makes it a texture */
    SDL_Surface *image = SDL_LoadBMP(sprite->path);
    memcpy(sprite->surface, image, sizeof(SDL_Surface));
    memcpy(sprite->renderSurface, image, sizeof(SDL_Surface));

    if (image == NULL)
    {
        logWarning(printf("Could not find %s", sprite->path), 2);
    }
    else
    {
        sprite->texture = SDL_CreateTextureFromSurface(window->window_renderer, image);
        logClean(printf("Cleaning %lu bytes from sprite texture", sizeof(image)), 0);

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
}

void RenderTextureFromText(Comp_Image *sprite, Comp_Window *window, int fontSize, SDL_Color color, char text[200])
{
    /*
    TTF_Font *Sans = TTF_OpenFont(sprite->path, 24);
    if (Sans == NULL)
    {
        logWarning(printf("Could not find %s", sprite->path), 2);
    }
    else
    {
        SDL_Surface *image = TTF_RenderText_Solid(Sans, text, color);
        sprite->texture = SDL_CreateTextureFromSurface(window->window_renderer, image);
        logClean(printf("Cleaning %lli bytes from sprite texture", sizeof(image)), 0);
        SDL_FreeSurface(image);

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
    */
}

void MakeSprite(Entity window, Entity sprite)
{

    logTrace(printf("Finished Configuration"), 2);

    sprite->components.image->texture_rect.x = sprite->components.transform->position.x; // the x coordinate
    sprite->components.image->texture_rect.y = sprite->components.transform->position.y; // the y coordinate
    sprite->components.image->texture_rect.w = sprite->components.transform->scale.x;    // the width of the texture
    sprite->components.image->texture_rect.h = sprite->components.transform->scale.y;    // the height of the texture

    /* I want to scale the sprites to a 192 by 108 pixel aspect so we calculate these Sync values */
    sprite->components.image->xSync = windowX / 192;
    sprite->components.image->ySync = windowY / 108;
}

void AddImageComponent(Entity e)
{
    e->components.image = malloc(sizeof(Comp_Image));
    memset(e->components.image, 0, sizeof(Comp_Image));
    e->components.CompImageIndex = 1;
    logTrace(printf("Image component allocated with address %p", e->components.image), 1);
}

int MouseInSpriteBox(Entity e, Entity window)
{

    // e->components.transform->position.x = x / e->components.image->xSync;
    // e->components.transform->position.y = y / e->components.image->ySync;

    int bLeftX = e->components.transform->position.x + (e->components.transform->scale.x * e->components.image->imageSizeX);
    int bLeftY = e->components.transform->position.y + (e->components.transform->scale.y * e->components.image->imageSizeY);

    // SDL_Log("Mouse cursor is at %f, %f", window->components.window->mousePosition.x, window->components.window->sync.y);

    if (e->components.transform->position.x <= window->components.window->mousePositionX && window->components.window->mousePositionX <= bLeftX && e->components.transform->position.y <= window->components.window->mousePositionY && window->components.window->mousePositionY <= bLeftY)
        return 0;
    else
        return -1;
}

Entity CreateImageComponentText(ECSContainer container, Entity window, struct Vector2 position, struct Vector2 imageScale, int fontSize, SDL_Color color, char fontPath[200], char text[200])
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

    strcpy(e->components.image->path, fontPath);
    MakeSprite(window, e);
    RenderTextureFromText(e->components.image, window->components.window, fontSize, color, text);

    return e;
}

Entity CreateImageComponent(ECSContainer container, Entity window, struct Vector2 position, struct Vector2 imageScale, char path[200])
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
    RenderTextureFromImage(e->components.image, window->components.window);

    return e;
}

void UpdateImageComponent(Entity window, Entity entity)
{
    RenderSprite(window, entity);
}
