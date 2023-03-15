#pragma once

#include "window.hpp"
#include "texture.hpp"

class Text
{
    protected:
        std::string character;
        SDL_Color color;
        Texture characterTexture;
        SDL_Point characterCoordinates;
        TTF_Font *charFont = NULL;
        SDL_Point dimensions;  // x-> width, y-> height
        int size;
    
    public:
        Text() {}

        Text(Window &window, std::string character, SDL_Color color = {255, 255, 255, 255}, int size = 13);

        void free();

        SDL_Point getCoordinate();

        void setCoordinate(SDL_Point point);

        void render(Window &window);
};