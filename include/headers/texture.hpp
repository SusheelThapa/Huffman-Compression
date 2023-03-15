#pragma once

#include "window.hpp"

class Texture
{

private:
    // private variables

    SDL_Texture *texture = nullptr;

    int width;

    int height;

public:
    // public functions

    Texture();

    void free();
    

#if defined SDL_IMAGE_MAJOR_VERSION

    Texture(Window &, std::string);

#endif

#if defined(SDL_TTF_MAJOR_VERSION)

    Texture(Window &, std::string, TTF_Font *, SDL_Color);

#endif

    ~Texture();

#if defined SDL_IMAGE_MAJOR_VERSION

    bool loadFromFile(Window &window, std::string);

#endif

#if defined(SDL_TTF_MAJOR_VERSION)

    bool loadFromText(Window &window, TTF_Font *font, std::string text, SDL_Color color);

#endif

    int getWidth();

    int getHeight();

    void render(Window &window, int x, int y, SDL_Rect *render_rect = NULL, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
};
