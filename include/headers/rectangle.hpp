#pragma once

#include "window.hpp"

class Rectangle
{
private:
    SDL_Color color;
    SDL_Point startingCords;
    int width, height;

public:
    Rectangle();
    Rectangle(SDL_Point startingCords, int width, int height);

    void setHeight(int height);
    void setWidth(int width);
    void setStartingCords(SDL_Point startingCords);

    void setColor(int r, int g, int b, int a);

    SDL_Color getColor();

    void render(Window &window);
};