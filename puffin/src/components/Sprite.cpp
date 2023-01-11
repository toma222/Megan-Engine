
#include "core/Core.h"
#include "core/Logging.h"
#include "graphics/Window.h"
#include "core/Application.h"

#include "graphics/Texture.h"
#include "graphics/Surface.h"

#include <SDL.h>
#include <SDL_image.h>

#include <string>

#include "Component.h"
#include "Transform.h"

#include "Sprite.h"

namespace pn
{
    namespace components
    {
        Sprite::Sprite(Transform *linkedTransform, std::string path)
        {
            /*
            m_transformREF = linkedTransform;
            m_filePath = path;

            m_textureRect = new SDL_Rect;
            m_surface = graphics::CreateSurfaceFromImage(m_filePath);

            // graphics::PutPixelSurface(m_surface, 1, 0, {255, 0, 0});

            RenderTexture();
            */
        }

        void Sprite::CalculateTextureRect()
        {
            /*
            m_textureRect->x = (int)m_transformREF->GetPosition().x; // the x coordinate
            m_textureRect->y = (int)m_transformREF->GetPosition().y; // the y coordinate
            m_textureRect->w = (int)m_transformREF->GetScale().x;    // the width of the texture
            m_textureRect->h = (int)m_transformREF->GetScale().y;    // the height of the texture
            */
        }

        void Sprite::RenderTexture()
        {
            /*
            m_texture = graphics::CreateTextureFromSurface(m_surface);
            CalculateTextureRect();
            */
        }

        void Sprite::UpdateComponent()
        {
            /*
            CalculateTextureRect();
            SDL_RenderCopy(Application::Get()->GetWindow()->GetRenderer(), m_texture, NULL, m_textureRect);
            */
        }
    } // namespace components

} // namespace pn
