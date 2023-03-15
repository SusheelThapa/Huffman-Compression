#include "text.hpp"

Text::Text(Window &window, std::string character, SDL_Color color, int size)
{
    this->character = character;
    this->color = color;
    this->size = size;

    this->charFont = TTF_OpenFont("resources/font/Helvetica.ttf", size);
    characterTexture.loadFromText(window, charFont, character, color);
    dimensions.x = characterTexture.getWidth();
    dimensions.y = characterTexture.getHeight();
}

void Text::free()
{
    this->characterTexture.free();
}

SDL_Point Text::getCoordinate()
{
    return this->characterCoordinates;
}

void Text::setCoordinate(SDL_Point point)
{
    this->characterCoordinates = point;
}