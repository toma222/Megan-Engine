
#include "core/Core.h"
#include "core/Application.h"

#include "graphics/Surface.h"
#include "graphics/Texture.h"

#include "Viewport.h"

#include <vector>
#include <array>

namespace pn
{
    Viewport::Viewport(int vsizex, int vsizey)
    {
        PN_CORE_INFO("Creating viewport");
        m_vSizeX = vsizex;
        m_vSizeY = vsizey;

        m_viewportSurface = graphics::CreateSurfaceFromImage("C:/Users/Aidan/Documents/programming/EngineInADay/test/Viewport192x108.bmp"); // SDL_CreateRGBSurface(SDL_SWSURFACE, 50, 50, sizeof(Uint32), 0, 0, 0, 0);
    }

    Viewport::~Viewport()
    {
        return;
    }

    void Viewport::AddTextureToViewport(components::Sprite *texture)
    {
        m_renderSprites.push_back(texture);
    }

    void Viewport::RenderTextureToViewPort()
    {
        // SDL_Surface *surf;

        SDL_LockSurface(m_viewportSurface);

        for (auto &&sprite : m_renderSprites)
        {
            for (int x = 0; x < (int)sprite->GetTransform()->GetScale().x; x++)
            {
                for (int y = 0; y < (int)sprite->GetTransform()->GetScale().y; y++)
                {
                    // get the pixel value from the current sprite
                    // m_viewportSurface
                    // graphics::GetPixelColor(sprite->GetSurface(), x, y);

                    // printf("%i\n", y);
                    // SDL_LockSurface(sprite->GetSurface());

                    SDL_Color color = graphics::GetPixelColor(sprite->GetSurface(), 0, 0);

                    // graphics::PutPixelSurface(m_viewportSurface,
                    //                           x,
                    //                           y,
                    //                           color);
                    //  graphics::GetPixelColor(sprite->GetSurface(), x, y));

                    graphics::PutPixelSurface(m_viewportSurface, std::min(x, 255),
                                              std::min(y, 192),
                                              color);
                }
            }
        }

        m_viewportTexture = graphics::CreateTextureFromSurface(m_viewportSurface);
    }
} // namespace pn
