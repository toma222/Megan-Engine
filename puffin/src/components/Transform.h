#pragma once

#include "core/Core.h"
#include "math/vector.h"
#include "Component.h"

namespace pn
{
    namespace components
    {
        class Transform : public Component
        {
        private:
            Vector3f m_position;
            Vector2f m_scale;

        public:
            void Translate(Vector3f pos);
            void Translate(float x, float y, float z);

            Transform(float x, float y, float z, float width, float height);
            Transform(Vector3f position, Vector2f scale);

            Vector3f GetPosition() { return m_position; };
            Vector2f GetScale() { return m_scale; };

            void UpdateComponent() override;
        };
    } // namespace components

} // namespace pn
