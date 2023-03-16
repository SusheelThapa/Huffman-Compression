#include "text.hpp"

Text::Text(std::string text, SDL_Point point, SDL_Color color, int size, bool coloredText)
{
    this->text = text;
    this->renderCoordinate = point;
    this->textColor = color;
    this->size = size;
    this->coloredText = coloredText;
    if(this->coloredText == true)
    {
        this->textColor = {0, 255, 0, 255};
    }
}

Text::~Text()
{
    this->textTexture.free();
    TTF_CloseFont(this->mainFont);
    mainFont = NULL;
}

void Text::free()
{
    this->textTexture.free();
}

void Text::render(Window &window)
{
        this->createTextTexture(window, size);

        SDL_SetRenderDrawColor(window.renderer, this->textColor.r, this->textColor.g, this->textColor.b, this->textColor.a);

        SDL_Rect renderRect = {renderCoordinate.x - window.offsetCords.x, renderCoordinate.y - window.offsetCords.y, dimensions.x, dimensions.y};

        textTexture.render(window, renderCoordinate.x, renderCoordinate.y, NULL, &renderRect);
}

SDL_Point Text::getCoordinate()
{
    return this->renderCoordinate;
}

void Text::setCoordinate(SDL_Point point)
{
    this->renderCoordinate = point;
}