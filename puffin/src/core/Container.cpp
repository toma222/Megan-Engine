
#include "Core.h"
#include "Container.h"
#include "Logging.h"
#include "components/Component.h"

#include <memory>
#include <vector>

namespace pn
{
    Container::Container(int initialSize)
    {
        PN_CORE_INFO("Container Constructor called");
        m_pool.resize(initialSize);
    }

    Entity *Container::AddEntity()
    {
        // TODO, this.
        m_IDCounter++;

        return new Entity(m_IDCounter);
    }

    void Container::UpdateComponents()
    {
        for (size_t i = 0; i < m_pool.size(); i++)
        {
            if (m_pool[i] != NULL)
            {
                // Update the component
                m_pool[i]->UpdateComponent();
            }
        }
    }
} // namespace pn
