#include "texture.hpp"

Texture::Texture()
{
    /*Initalize the Texture*/
    width = 0;
    height = 0;
    texture = NULL;
}

#if defined SDL_IMAGE_MAJOR_VERSION
Texture ::Texture(Window &window, std::string image_path)
{
    this->loadFromFile(window, image_path);
}
#endif

#if defined(SDL_TTF_MAJOR_VERSION)

Texture ::Texture(Window &window, std::string text, TTF_Font *font, SDL_Color color)
{
    this->loadFromText(window, font, text, color);
}

#endif

Texture::~Texture()
{
    /* Free up the memory used up by the Texture objects*/
    this->free();
}

#if defined SDL_IMAGE_MAJOR_VERSION

bool Texture::loadFromFile(Window &window, std::string path)
{
    // Get rid of all the previous texture
    free();

    /*Create new surface outof image path*/
    SDL_Surface *new_surface = IMG_Load(path.c_str());

    if (new_surface == nullptr)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    /* Convert the surface generated to texture*/
    texture = SDL_CreateTextureFromSurface(window.renderer, new_surface);

    if (texture == nullptr)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    /*Set the width and height of the texture*/
    width = new_surface->w;
    height = new_surface->h;

    std::cout << "Height = " << height << std::endl;
    std::cout << "Width = " << width << std::endl;

    /*Free up the surface*/
    SDL_FreeSurface(new_surface);

    return true;
}
#endif

#if defined SDL_TTF_MAJOR_VERSION

bool Texture::loadFromText(Window &window, TTF_Font *font, std::string text, SDL_Color color)
{
    /*Create a surface outof text provide*/
    SDL_Surface *temporary_surface = TTF_RenderText_Solid(font, text.c_str(), color);

    if (temporary_surface == NULL)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    /*Create texture outof surface provided*/
    texture = SDL_CreateTextureFromSurface(window.renderer, temporary_surface);
    if (texture == NULL)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    /*Set the height and width of the surface*/
    width = temporary_surface->w;
    height = temporary_surface->h;

    /*Free up the surface*/
    SDL_FreeSurface(temporary_surface);

    return true;
}
#endif

void Texture::free()
{
    /*Free up the memory used up by the texture objects*/
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}

int Texture::getWidth()
{
    return width;
}

int Texture::getHeight()
{
    return height;
}

void Texture::render(Window &window, int x, int y,
                     SDL_Rect *render_rect, double angle,
                     SDL_Point *center, SDL_RendererFlip flip)
{

    SDL_Rect renderQuad = {x, y, width, height};
    if (render_rect != nullptr)
    {
        renderQuad.w = render_rect->w;
        renderQuad.h = render_rect->h;
    }

    window.checkOffset(*render_rect);

    SDL_RenderCopyEx(window.renderer, texture, render_rect, &renderQuad, angle, center, flip);
}