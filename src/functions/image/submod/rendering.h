
#include "../../../ecs/ecs.h"
#include "../../../utils/logging.h"
#include "../../genericsHeader.h"

#include "../../../utils/math/MMath.h"
#include "../../../utils/macros.h"

void PutPixel(SDL_Surface *image, int x, int y, int b, int g, int r)
{
    Uint8 *const target_pixel = ((Uint8 *)image->pixels + x * image->pitch + y * image->format->BytesPerPixel);
    target_pixel[0] = b; // b
    target_pixel[1] = g;   // g
    target_pixel[2] = r;   // r
}

void CalculateLights(Entity renderer){

    memset(renderer->components.deferedRenderer->lightBuffer,0,sizeof(renderer->components.deferedRenderer->lightBuffer));//renderer->components.deferedRenderer->lightBuffer;

    for (size_t x = 0; x < 192; x++)
    {
        for (size_t y = 0; y < 108; y++)
        {
            double power = 0;

            for (size_t lights = 0; lights < renderer->components.deferedRenderer->lights; lights++)
            {
                double distance = sqrt(
                    (renderer->components.deferedRenderer->light[lights].position.x - x) * (renderer->components.deferedRenderer->light[lights].position.x - x)
                    + (renderer->components.deferedRenderer->light[lights].position.y - y) * (renderer->components.deferedRenderer->light[lights].position.y - y)
                );

                power += fmin(pow(renderer->components.deferedRenderer->light[lights].strength, distance) * renderer->components.deferedRenderer->light[lights].radiance, 1);
            }

            renderer->components.deferedRenderer->lightBuffer[x][y] = power;//fmin(power,0);
        }
    }
}

void RenderImageDefered(Entity renderer, Entity sprite)
{
    int xSize = sprite->components.image->surface->w;
    int ySize = sprite->components.image->surface->h;

    for (size_t x = 0; x < xSize; x++)
    {
        for (size_t y = 0; y < ySize; y++)
        {
            // take max lol
            double lightStrength = renderer->components.deferedRenderer->lightBuffer
                [(int)(fminf(x + sprite->components.transform->position.x,192))]
                [(int)(fminf(y + sprite->components.transform->position.y,108))];
            // light[pixelIndex] = lightStrength;
            //PutPixel(sprite->surface, width, height, SDL_MapRGB(sprite->surface->format, lightStrength * 255, lightStrength * 255, lightStrength * 255));
            
            // RGB colors aquired!
            Uint8 *const target_pixel = ((Uint8 *)sprite->components.image->surface->pixels + y * sprite->components.image->surface->pitch + x * sprite->components.image->surface->format->BytesPerPixel);

            PutPixel(
                sprite->components.image->renderSurface, y, x,
                fmin(target_pixel[0] * lightStrength, 255), 
                fmin(target_pixel[1] * lightStrength, 255), 
                fmin(target_pixel[2] * lightStrength, 255)
            );
        }
    }
}


void RenderTextureFromSurface(Comp_Image *sprite, Comp_Window *window)
{
    sprite->texture = SDL_CreateTextureFromSurface(window->window_renderer, sprite->renderSurface);

    if (SDL_RenderCopy(window->window_renderer, sprite->texture, NULL, &sprite->texture_rect) < 0)
    {
        SDL_GetError();
        logError(printf(" %s", SDL_GetError()));
    }
    else
    {
        //logTrace(printf("Sprite Successfully Drawn"), 0);
    }
}

void DeferedRenderSprite(Entity sprites, Entity render, Entity window){
    RenderImageDefered(render, sprites);
    RenderTextureFromSurface(sprites->components.image, window->components.window);
}

void RenderSurfaceFromImage(Comp_Image *sprite, Comp_Window *window)
{
    /* Loads the image in and makes it a texture */
    SDL_Surface *image = SDL_LoadBMP(sprite->path);
    SDL_Surface *renderImage = SDL_LoadBMP(sprite->path);

    if (image == NULL)
    {
        logWarning(printf("Could not find %s", sprite->path), 2);
    }
    else
    {
        sprite->surface = image;
        sprite->renderSurface = renderImage;
    }
}

Entity CreateImageComponentRender(ECSContainer container, Entity window, struct Vector2 position, struct Vector2 imageScale, char path[200], Entity renderer)
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

    e->components.image->defered = 1;

    strcpy(e->components.image->path, path);
    MakeSprite(window, e);
    RenderSurfaceFromImage(e->components.image, window->components.window);
    CalculateLights(renderer);
    RenderImageDefered(renderer ,e);
    RenderTextureFromSurface(e->components.image, window->components.window);

    return e;
}

void AddLight(Entity renderer, struct Vector2 position, int radiance, float strength){
    renderer->components.deferedRenderer->light[renderer->components.deferedRenderer->lights].position = position;
    renderer->components.deferedRenderer->light[renderer->components.deferedRenderer->lights].radiance = radiance;
    renderer->components.deferedRenderer->light[renderer->components.deferedRenderer->lights].strength = strength;
    renderer->components.deferedRenderer->lights++;
    CalculateLights(renderer);
    // RenderTextureFromSurface(e->components.image, window->components.window);
}

Entity CreateDeferedRenderComponent(ECSContainer container, Entity window){
    Entity e = CreateEntity(container);   

    e->components.deferedRenderer = malloc(sizeof(Comp_DeferedRender));
    memset(e->components.deferedRenderer, 0, sizeof(Comp_DeferedRender));
    e->components.DeferedRendererIndex = 1;
    logTrace(printf("Defered Renderer component allocated with address %p", e->components.deferedRenderer), 1);

    //container->engineEntities->deferedIndex = 1;

    return e;
}

void UpdateDeferedRenderer(ECSContainer container, Entity window, Entity renderer){
    
    // Loop through sprites
    for (size_t sprite = 0; sprite < renderer->components.deferedRenderer->sprites; sprite++)
    {
        // Update them to the main canvas
    }
}