
#pragma once

#include "core/Core.h"
#include "math/vector.h"
#include "core/Window.h"
#include <string>

#include "Transform.h"
#include "Component.h"

#include <SDL.h>

namespace pn
{
    namespace components
    {
        class Sprite : public Component
        {
        private:
            std::string m_filePath;

            SDL_Texture *m_texture;
            SDL_Surface *m_surface;

            Transform *m_transformREF;

            SDL_Rect *m_textureRect;

        public:
            SDL_Renderer *m_render;

            Sprite(Transform *linkedTransform, std::string path);

            void UpdateComponent() override;

            void CalculateTextureRect();
            void CleanSDLSurface() { SDL_FreeSurface(m_surface); };
            void RenderTexture();

            SDL_Texture *GetTexture() { return m_texture; };
            SDL_Surface *GetSurface() { return m_surface; };
            Transform *GetTransform() { return m_transformREF; };
        };
    } // namespace componentss
} // namespace pn
