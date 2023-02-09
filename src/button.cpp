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

void Button::render(Window &window)
{
    this->createButtonTexture(window);

    buttonRect.setColor(255, 255, 255, 255);
    buttonRect.render(window);

    buttonTexture.render(window,
                         this->padding.x + this->renderCoordinate.x - window.offsetCords.x,
                         this->padding.y + this->renderCoordinate.y - window.offsetCords.y);
}