
#pragma once

#include "../components/comps_screen.h"
#include "../ecs/ecs.h"

#define USI unsigned short int

// Transform Functions
void AddTransformComponent(Entity e);
Entity CreateTransformComponent(ECSContainer container, Entity window);
void UpdateTransformComponent(Entity entity);

// Window Functions
void MakeWindow(Entity entity, int xSize, int ySize);
int RenderWindow(Entity window);

// Generic Window Functions
void AddWindowComponent(Entity e);
Entity CreateWindowComponent(ECSContainer container, int sizeX, int sizeY);
void UpdateWindowComponent(Entity entity);

// Image Functions
void MakeSprite(Entity Window, Entity Sprite);
void RenderSprite();
// Generic Image Functions
void AddImageComponent(Entity e);
Entity CreateImageComponent(ECSContainer container, Entity window, struct Vector2 position, struct Vector2 Scale, char path[200]);
void UpdateImageComponent(Entity window, Entity entity);

// MMath functions
