
#pragma once

#include "../components/componentsGenarics.h"

#define MAXENTITIES 200

// Components HOLD data

// Holds Components
struct Struct_Entity
{
    // stores the components in the entity
    unsigned short int id;

    // Checks if the component has been initialized
    unsigned int using;

    struct Components components;
};

struct Component_Tracker;

typedef struct Struct_Entity *Entity;

// Holds components crucial for running the GAME engine
struct Engine_Entities
{
    int windowIndex;
};

struct Engine_Entities;

struct Struct_ECSContainer
{
    // Contains all possible components
    unsigned short int entitiesPointer;
    Entity entities[500];
    struct Engine_Entities *engineEntities;
};

struct Struct_ECSContainer;
typedef struct Struct_ECSContainer *ECSContainer;

// Adds an entity to the system
Entity CreateEntity(ECSContainer container);

// Makes space in memory for the entity component system
void StartECS(ECSContainer container);

// Makes sure that the entity is removed from the scene with care
void DestroyEntity(ECSContainer container, unsigned short int id);

// Updates all the components
void UpdateECS(ECSContainer container, Entity window);
