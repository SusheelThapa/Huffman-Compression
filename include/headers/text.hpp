#pragma once

#include "window.hpp"
#include "texture.hpp"

class Text
{
private:
    std::string text;
    SDL_Color textColor;
    SDL_Point renderCoordinate;
    SDL_Point dimensions;      // x-> width, y-> height
    Texture textTexture;
    TTF_Font *mainFont = NULL;
    int size;
    int wrapLength;

    void createTextTexture (Window &window, int size)
    {
        mainFont = TTF_OpenFont("resources/font/Helvetica.ttf", size);
        textTexture.loadFromText(window, mainFont, text, textColor, wrapLength);
        dimensions.x = textTexture.getWidth();
        dimensions.y = textTexture.getHeight();
    }

public:

    Text() {}
    Text(std::string text, SDL_Point point, SDL_Color color, int size=13, int wrapLength = 750);
    ~Text();
    void free();
    void render(Window &window);
    SDL_Point getCoordinate();
    void setCoordinate(SDL_Point point);
};