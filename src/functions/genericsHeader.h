
#pragma once

#include "../components/comps_screen.h"
#include "../ecs/ecs.h"

#define USI unsigned short int

// Transform Functions
void movePosition(Entity e, float x, float y);
void setPosition(Entity e, float x, float y);
void moveScale(Entity e, float x, float y);
void setScale(Entity e, float x, float y);
void AddTransformComponent(Entity e);
Entity CreateTransformComponent(ECSContainer container, Entity window);
void UpdateTransformComponent(Entity entity);

// Window Functions
void MakeWindow(Entity entity, int xSize, int ySize);
int RenderWindow(Entity window);
void AddWindowComponent(Entity e);
Entity CreateWindowComponent(ECSContainer container, int sizeX, int sizeY);
void UpdateWindowComponent(Entity entity);

// Image Functions
void MakeSprite(Entity Window, Entity Sprite);
void RenderSprite();
int MouseInSpriteBox(Entity e, Entity window);
void AddImageComponent(Entity e);
Entity CreateImageComponent(ECSContainer container, Entity window, struct Vector2 position, struct Vector2 imageScale, char path[200]);
void UpdateImageComponent(Entity window, Entity entity);
Entity CreateImageComponentText(ECSContainer container, Entity window, struct Vector2 position, struct Vector2 imageScale, int fontSize, SDL_Color color, char fontPath[200], char text[200]);

// Image Processing Functions
void RenderSurfaceFromImage(Comp_Image *sprite, Comp_Window *window);
Entity CreateImageComponentProcessing(ECSContainer container, Entity window, struct Vector2 position, struct Vector2 imageScale, char path[200]);
Entity CreateImageComponentProcessingBlank(ECSContainer container, Entity window, struct Vector2 position, struct Vector2 imageScale);
void RenderTextureFromSurface(Comp_Image *sprite, Comp_Window *window);
void PutPixel(SDL_Surface *image, int x, int y, Uint32 color);

// Alignment Functions
void addAlignmentComponent(Entity e);
Entity CreateAlignmentComponent(ECSContainer container, struct Vector2 cellSize, struct Vector2 cellPadding, struct Vector2 rootPosition);
void UpdateAlignmentComponent(Entity alignment);
void CalculateAlignmentPosition(Entity alignment);
void AddImageToAlignment(Entity alignment, Entity sprite);
// MMath functions
