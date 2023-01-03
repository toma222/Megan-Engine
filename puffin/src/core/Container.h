
#pragma once

#include "Core.h"
#include "components/Component.h"
#include <memory>
#include <vector>

// Only 2 different components
#define UNIQUE_COMPONENTS 2

namespace pn
{
    class Entity
    {
    private:
        unsigned int m_CompID;
        unsigned int m_ID;

    public:
        Entity(unsigned int ID) { m_ID = ID; };
    };

    class Container
    {
    private:
        // All the components in one array
        std::vector<components::Component *> m_pool;

    public:
        unsigned int m_IDCounter;

        Container(int initialSize);
        Entity *AddEntity();
        void UpdateComponents();

        template <typename T, typename... Args>
        T *AddComponent(Entity *ent, Args &&...mArgs)
        {
            T *comp = new T(std::forward<Args>(mArgs)...);

            m_pool.insert(m_pool.end(), comp);

            return comp;
        }

        // @warning This is a tomorrow problem...
        template <typename T>
        T *GetComponent(Entity *entity)
        {
            return NULL;
        }
    };

    static Container *container;
} // namespace pn
