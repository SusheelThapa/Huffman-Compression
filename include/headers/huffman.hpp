#include "window.hpp"
#include "texture.hpp"
#include "button.old.hpp"

class Huffman
{

private:
    SDL_Point clickedPosition;
    SDL_Event e;

public:
    Window window;

    /*Texture to represent buttons in the program*/
    Texture randomize, count;

    Huffman()
    {
       randomize.loadFromFile(window, "resources/images/button_randomize.png");
       count.loadFromFile(window, "resources/images/button_count.png");
    }

    void handleEvent()
    {
        while (SDL_PollEvent(&this->e) != 0)
        {
            // *Yo section ma Scroll event handle huncah hai ra

            if (e.type == SDL_QUIT ||
                e.type == SDL_MOUSEMOTION ||
                e.type == SDL_MOUSEBUTTONDOWN ||
                e.type == SDL_MOUSEBUTTONUP)
            {
                window.handleEvent(e);
            }

            // * Aba malai yo section ma button click handle garna xa

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&clickedPosition.x, &clickedPosition.y);
            }

            if (e.type == SDL_MOUSEBUTTONUP)
            {
                SDL_Point currentClickedPosition;

                SDL_GetMouseState(&currentClickedPosition.x, &currentClickedPosition.y);

                if (currentClickedPosition.x == clickedPosition.x && currentClickedPosition.y == clickedPosition.y)
                {

                    std::cout << "Button is clicked";

                    /**
                     * TODO: Logic to identify which button is clicked
                     */
                }
            }
        }
    }
};