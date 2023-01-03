
#include "core/Core.h"

#include "components/Sprite.h"

#include <SDL.h>

#include <vector>
#include <array>

namespace pn
{
    class Viewport
    {
    private:
        int m_vSizeX;
        int m_vSizeY;

        std::vector<components::Sprite *> m_renderSprites;

        SDL_Surface *m_viewportSurface;
        SDL_Texture *m_viewportTexture;

    public:
        Viewport(int vsizex, int vsizey);

        void RenderTextureToViewPort();
        void AddTextureToViewport(components::Sprite *texture);

        SDL_Texture *GetTexture() { return m_viewportTexture; };

        ~Viewport();
    };
} // namespace pn
