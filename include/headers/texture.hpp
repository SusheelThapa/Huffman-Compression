#pragma once

#include "window.hpp"

class Texture
{

private:
    // private variables

    SDL_Texture *texture = nullptr;

    int width;
    int height;

    SDL_Point startingCoordinate;

public:
    // public functions

    Texture();

    void free();

    bool isMouseClicked(Window &window, SDL_Point clickedPosition);


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

    bool loadFromText(Window &window, TTF_Font *font, std::string text, SDL_Color color, int wrapValue = 750);

#endif

    int getWidth();

    int getHeight();

    void render(Window &window, int x, int y, SDL_Rect *src_rect = NULL, SDL_Rect *dst_rect = NULL);
};