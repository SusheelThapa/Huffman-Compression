#include "button.hpp"

void Button::setText(std::string text)
{
    this->text = text;
}

void Button::setRenderCoordinate(int x, int y)
{
    this->renderCoordinate = {x, y};
    buttonRect.setStartingCords({x, y});
}

void Button::setPadding(int left, int top, int right, int bottom)
{
    this->padding = {left, top, right, bottom};
}

void Button::setPadding(int horizontal, int vertical)
{
    this->padding = {horizontal, vertical, horizontal, vertical};
}

void Button::setPadding(int all)
{
    this->padding = {all, all, all, all};
}

void Button::setBackgroundColor(SDL_Color color)
{
    buttonRect.setColor(color.r, color.g, color.b, color.a);
}

void Button::setTextColor(SDL_Color color)
{
    this->textColor = color;
}

void Button::render(Window &window)
{
    this->createButtonTexture(window);

    buttonRect.render(window);

    buttonTexture.render(window,
                         this->padding.x + this->renderCoordinate.x - window.offsetCords.x,
                         this->padding.y + this->renderCoordinate.y - window.offsetCords.y);
}