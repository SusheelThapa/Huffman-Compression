#pragma once

#include "window.hpp"
#include "text.hpp"
#include "queue.hpp"

class Rectangle
{
protected:
    SDL_Color color = {50, 50, 50, 255};
    SDL_Point startingCords;
    int width, height;

public:
    Rectangle();
    Rectangle(SDL_Point startingCords, int width, int height);

    void setHeight(int height);
    void setWidth(int width);
    void setStartingCords(SDL_Point startingCords);

    void setColor(SDL_Color color);

    SDL_Color getColor();

    void render(Window &window);
};

// class randomizeRectangle : protected Rectangle
// {       

// };

// class countRectangle : protected Rectangle
// {

// };

// class encodeRectangle : protected Rectangle
// {

// };