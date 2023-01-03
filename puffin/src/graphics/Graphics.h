#pragma once

#include "core/Core.h"
#include "math/vector.h"
#include "SDL2/SDL.h"
#include "components/Sprite.h"

namespace pn
{
    namespace graphics
    {
        class Graphics
        {
        private:
            SDL_Renderer *m_renderer;

            // ONLY-HOLDS-10-SPRITES
            puffin::components::Sprite *m_SpritePool[10];

        public:
            void Attach(SDL_Renderer *render) { m_renderer = render; };
            void RenderSprites();
        };
    } // namespace graphics
} // namespace pn
