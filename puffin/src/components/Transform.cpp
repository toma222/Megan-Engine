#include "core/Core.h"
#include "math/vector.h"
#include "Transform.h"

namespace pn
{
    namespace components
    {
        void Transform::UpdateComponent()
        {
            return;
        }

        Transform::Transform(float x, float y, float z, float width, float height)
        {
            m_position.x = x;
            m_position.y = y;
            m_position.z = z;

            m_scale.x = width;
            m_scale.y = height;
        }

        Transform::Transform(Vector3f position, Vector2f scale)
        {
            m_position = position;
            m_scale = scale;
        }

        void Transform::Translate(Vector3f pos)
        {
            m_position.x += pos.x;
            m_position.y += pos.y;
            m_position.z += pos.z;
        }

        void Transform::Translate(float x, float y, float z)
        {
            m_position.x += x;
            m_position.y += y;
            m_position.z += z;
        }
    } // namespace components
} // namespace pn
