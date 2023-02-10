#include "window.hpp"
#include "texture.hpp"
#include "button.hpp"

class Huffman
{

private:
    SDL_Event e;

public:
    Window window;
    Button randomize, count;

    Huffman()
    {
        randomize.setRenderCoordinate(200, 20);
        randomize.setRenderCoordinate(10, 20);

        count.setRenderCoordinate(200, 20);

        randomize.setText("Randomize");
        count.setText("Count");

        randomize.setBackgroundColor({0, 0, 255, 255});
        randomize.setTextColor({255, 255, 255, 255});
    }

    void handleEvent()
    {
        while (SDL_PollEvent(&this->e) != 0)
        {
            if(e.type == SDL_QUIT || e.type == SDL_MOUSEMOTION)
            {
                window.handleEvent(e);
            }
        }
    }
};