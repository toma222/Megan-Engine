
#include "../../data/ecs.h"
#include "../../utils/logging.h"
#include "../genericsHeader.h"

#include "../../utils/math/MMath.h"
#include "../../../game/settings.h"

#include <math.h>
/*
LOST CENTURY
https://lospec.com/palette-list/lost-century

int palletLength = 16;
int const colors[palletLength] = {
0xd1b187,
0xc77b58,
0xae5d40,
0x79444a,
0x4b3d44,
0xba9158,
0x927441,
0x4d4539,
0x77743b,
0xb3a555,
0xd2c9a5,
0x8caba1,
0x4b726e,
0x574852,
0x847875,
0xab9b8e
};
*/

// Demichrome957128

int palletLength = 24;
int const colors[24] = {
    0x000000,
    0x6f6776,
    0x9a9a97,
    0xc5ccb8,
    0x8b5580,
    0xc38890,
    0xa593a5,
    0x666092,
    0x9a4f50,
    0xc28d75,
    0x7ca1c0,
    0x416aa3,
    0x8d6268,
    0xbe955c,
    0x68aca9,
    0x387080,
    0x6e6962,
    0x93a167,
    0x6eaa78,
    0x557064,
    0x9d9f7f,
    0x7e9e99,
    0x5d6872,
    0x433455};
/*
int palletLength = 64;
int const colors[64] = {
    0x2e222f,
    0x3e3546,
    0x625565,
    0x966c6c,
    0xab947a,
    0x694f62,
    0x7f708a,
    0x9babb2,
    0xc7dcd0,
    0xffffff,
    0x6e2727,
    0xb33831,
    0xea4f36,
    0xf57d4a,
    0xae2334,
    0xe83b3b,
    0xfb6b1d,
    0xf79617,
    0xf9c22b,
    0x7a3045,
    0x9e4539,
    0xcd683d,
    0xe6904e,
    0xfbb954,
    0x4c3e24,
    0x676633,
    0xa2a947,
    0xd5e04b,
    0xfbff86,
    0x165a4c,
    0x239063,
    0x1ebc73,
    0x91db69,
    0xcddf6c,
    0x313638,
    0x374e4a,
    0x547e64,
    0x92a984,
    0xb2ba90,
    0x0b5e65,
    0x0b8a8f,
    0x0eaf9b,
    0x30e1b9,
    0x8ff8e2,
    0x323353,
    0x484a77,
    0x4d65b4,
    0x4d9be6,
    0x8fd3ff,
    0x45293f,
    0x6b3e75,
    0x905ea9,
    0xa884f3,
    0xeaaded,
    0x753c54,
    0xa24b6f,
    0xcf657f,
    0xed8099,
    0x831c5d,
    0xc32454,
    0xf04f78,
    0xf68181,
    0xfca790,
    0xfdcbb0,
};
*/

void PutPixel(SDL_Surface *image, int x, int y, int b, int g, int r)
{
    Uint8 *const target_pixel = ((Uint8 *)image->pixels + x * image->pitch + y * image->format->BytesPerPixel);
    target_pixel[0] = b; // b
    target_pixel[1] = g; // g
    target_pixel[2] = r; // r
}

void CalculateLights(Entity renderer)
{

    memset(renderer->components.deferedRenderer->lightBuffer, 0, sizeof(renderer->components.deferedRenderer->lightBuffer)); // renderer->components.deferedRenderer->lightBuffer;

    for (size_t x = 0; x < 192; x++)
    {
        for (size_t y = 0; y < 108; y++)
        {
            double power = 0;

            for (size_t lights = 0; lights < renderer->components.deferedRenderer->lights; lights++)
            {
                double distance = sqrt(
                    (renderer->components.deferedRenderer->light[lights].position.x - x) * (renderer->components.deferedRenderer->light[lights].position.x - x) + (renderer->components.deferedRenderer->light[lights].position.y - y) * (renderer->components.deferedRenderer->light[lights].position.y - y));

                power += fmin(pow(renderer->components.deferedRenderer->light[lights].strength, distance) * renderer->components.deferedRenderer->light[lights].radiance, 1);
            }

            renderer->components.deferedRenderer->lightBuffer[x][y] = fmin(power, 1);
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
                                       [(int)(fminf(x + sprite->components.transform->position.x, 192))]
                                       [(int)(fminf(y + sprite->components.transform->position.y, 108))];
            // light[pixelIndex] = lightStrength;
            // PutPixel(sprite->surface, width, height, SDL_MapRGB(sprite->surface->format, lightStrength * 255, lightStrength * 255, lightStrength * 255));

            // RGB colors aquired!
            Uint8 *const target_pixel = ((Uint8 *)sprite->components.image->surface->pixels + y * sprite->components.image->surface->pitch + x * sprite->components.image->surface->format->BytesPerPixel);

            int targetColor[3] = {target_pixel[0] * lightStrength, target_pixel[1] * lightStrength, target_pixel[2] * lightStrength};

            int closest = 257;
            int finalColor[3] = {0, 0, 0};

            for (size_t c = 0; c < palletLength; c++)
            {
                double distance = sqrt(
                    (((colors[c] >> 16) & 0xFF) - targetColor[0]) * (((colors[c] >> 16) & 0xFF) - targetColor[0]) +
                    (((colors[c] >> 8) & 0xFF) - targetColor[1]) * (((colors[c] >> 8) & 0xFF) - targetColor[1]) +
                    (((colors[c]) & 0xFF) - targetColor[2]) * (((colors[c]) & 0xFF) - targetColor[2]));

                if (closest > distance)
                {
                    closest = distance;
                    finalColor[2] = ((colors[c] >> 16) & 0xFF);
                    finalColor[1] = ((colors[c] >> 8) & 0xFF);
                    finalColor[0] = (colors[c] & 0xFF);
                }
            }

            PutPixel(
                sprite->components.image->renderSurface, y, x,
                fmin(finalColor[2], 255),
                fmin(finalColor[1], 255),
                fmin(finalColor[0], 255));
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
}

void DeferedRenderSprite(Entity sprites, Entity render, Entity window)
{
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

    e->components.transform->imageScale.x = imageScale.x;
    e->components.transform->imageScale.y = imageScale.y;

    e->components.image->defered = 1;

    strcpy(e->components.image->path, path);
    MakeSprite(window, e);
    RenderSurfaceFromImage(e->components.image, window->components.window);
    CalculateLights(renderer);
    RenderImageDefered(renderer, e);
    RenderTextureFromSurface(e->components.image, window->components.window);

    return e;
}

void AddLight(Entity renderer, struct Vector2 position, int radiance, float strength)
{
    renderer->components.deferedRenderer->light[renderer->components.deferedRenderer->lights].position = position;
    renderer->components.deferedRenderer->light[renderer->components.deferedRenderer->lights].radiance = radiance;
    renderer->components.deferedRenderer->light[renderer->components.deferedRenderer->lights].strength = strength;
    renderer->components.deferedRenderer->lights++;
    CalculateLights(renderer);
    // RenderTextureFromSurface(e->components.image, window->components.window);
}

Entity CreateDeferedRenderComponent(ECSContainer container, Entity window)
{
    Entity e = CreateEntity(container);

    e->components.deferedRenderer = malloc(sizeof(Comp_DeferedRender));
    memset(e->components.deferedRenderer, 0, sizeof(Comp_DeferedRender));
    e->components.DeferedRendererIndex = 1;
    logTrace(printf("Defered Renderer component allocated with address %p", e->components.deferedRenderer), 1);

    // container->engineEntities->deferedIndex = 1;

    return e;
}

void UpdateDeferedRenderer(ECSContainer container, Entity window, Entity renderer)
{

    // Loop through sprites
    for (size_t sprite = 0; sprite < renderer->components.deferedRenderer->sprites; sprite++)
    {
        // Update them to the main canvas
    }
}