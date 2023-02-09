#pragma once

#include "window.hpp"
#include "texture.hpp"
#include "rectangle.hpp"

class Button
{
    std::string text;
    SDL_Rect padding = {10, 10, 10, 10};
    SDL_Point renderCoordinate = {0, 0};

    Rectangle buttonRect;

    Texture buttonTexture;

    void createButtonTexture(Window &window)
    {
        TTF_Font *mainFont = TTF_OpenFont("resources/font/Helvetica-Bold.ttf", 16);
        buttonTexture.loadFromText(window, mainFont, text, {0, 0, 0, 0});

        buttonRect.setWidth(buttonTexture.getWidth() + padding.x + padding.w);
        buttonRect.setHeight(buttonTexture.getHeight() + padding.y + padding.h);
    }

public:
    void setText(std::string text);
    void setRenderCoordinate(int x, int y);

    void setPadding(int left, int top, int right, int bottom);
    void setPadding(int horizontal, int vertical);
    void setPadding(int all);

    void render(Window &window);
};