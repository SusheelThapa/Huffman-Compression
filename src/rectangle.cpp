#include "rectangle.hpp"

Rectangle::Rectangle()
{
    this->startingCords = {0, 0};
};

Rectangle::Rectangle(SDL_Point startingCords, int width, int height)
{
    this->startingCords = startingCords;
    this->width = width;
    this->height = height;
}

void Rectangle::setHeight(int height)
{
    this->height = height;
}

void Rectangle::setWidth(int width)
{
    this->width = width;
}

void Rectangle::setStartingCords(SDL_Point startingCords)
{
    this->startingCords = startingCords;
}

void Rectangle::setColor(int r, int g, int b, int a)
{
    this->color.r = r;
    this->color.g = g;
    this->color.b = b;
    this->color.a = a;
}

SDL_Color Rectangle::getColor()
{
    return this->color;
}

void Rectangle::render(Window &window)
{
    /*Render the fill rectangle of provide dimension and color in the screen*/
    SDL_SetRenderDrawColor(window.renderer, this->getColor().r, this->getColor().g, this->getColor().b, this->getColor().a);

    SDL_Rect rec = {this->startingCords.x - window.offsetCords.x,
                    this->startingCords.y - window.offsetCords.y,
                    this->width,
                    this->height};

    SDL_RenderFillRect(window.renderer, &rec);
}