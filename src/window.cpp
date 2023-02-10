#include "window.hpp"

bool Window::init()
{
    this->closed = false;

    bool status = true;

    // Initialize SDL with video and audio
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cout << "SDL couldn't initailize."
                  << std::endl
                  << "SDL_Error: "
                  << SDL_GetError()
                  << std::endl;
        status = false;
    }

    // Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
        printf("Warning: Linear texture filtering not enabled!");
    }

    /* Create Window */
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screenWidth, screenHeight,
        SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        std::cout << "Window couldn't be created"
                  << std::endl
                  << "SDL_Error: "
                  << SDL_GetError()
                  << std::endl;

        status = false;
    }

    /* Create vsynced renderer for window */
    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr)
    {
        std::cout << "Renderer couldn't be created out of window"
                  << std::endl
                  << "SDL_Error: "
                  << SDL_GetError()
                  << std::endl;
        return false;
    }

#if defined SDL_IMAGE_MAJOR_VERSION

    /* Initialize SDL_image to load PNG image */
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cout << "SDL_image couldn't be initialze to load PNG image."
                  << std::endl
                  << "SDL_Error: "
                  << IMG_GetError()
                  << std::endl;

        status = false;
    }

#endif

#if defined SDL_TTF_MAJOR_VERSION

    /* Initialize SDL_ttf*/
    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf couldn't be initialize."
                  << std::endl
                  << "SDL_Error: "
                  << TTF_GetError()
                  << std::endl;
        return false;
    }

#endif

    return status;
}

Window::Window()
{
    init();
}

Window::Window(std::string title)
{
    this->title = title;

    init();
}

Window::~Window()
{
    /*Destroy the renderer and window object*/
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

#if defined SDL_IMAGE_MAJOR_VERSION
    /*Quit SDL_image*/
    IMG_Quit();
#endif

#if defined SDL_TTF_MAJOR_VERSION
    /*Quit SDL_ttf*/
    TTF_Quit();
#endif

#if defined SDL_MIXER_MAJOR_VERSION
    /*Quit SDL_mixer*/
    Mix_Quit();
#endif

    /*Quit SDL*/
    SDL_Quit();
}

void Window::handleEvent(SDL_Event e)
{

    switch (e.type)
    {
    case SDL_QUIT:
        this->closed = true;
        break;

    case SDL_MOUSEMOTION:
        mousePos = {e.motion.x, e.motion.y};
        if (leftMouseButtonDown)
        {
            if (offsetCords.x < 0)
            {
                offsetCords.x = 0;
            }

            else if (offsetCords.x + screenWidth > worldWidth)
            {
                offsetCords.x = worldWidth - screenWidth;
            }

            else
            {
                offsetCords.x -= mousePos.x - startPan.x;
            }

            if (offsetCords.y < 0)
            {
                offsetCords.y = 0;
            }

            else if (offsetCords.y + screenHeight > worldHeight)
            {
                offsetCords.y = worldHeight - screenHeight;
            }

            else
            {
                offsetCords.y -= mousePos.y - startPan.y;
            }

            startPan.x = mousePos.x;
            startPan.y = mousePos.y;
        }
        break;

    case SDL_MOUSEBUTTONUP:
        if (leftMouseButtonDown && e.button.button == SDL_BUTTON_LEFT)
        {
            leftMouseButtonDown = false;
        }
        break;

    case SDL_MOUSEBUTTONDOWN:
        if (!leftMouseButtonDown && e.button.button == SDL_BUTTON_LEFT)
        {
            leftMouseButtonDown = true;
            startPan.x = mousePos.x;
            startPan.y = mousePos.y;
        }
        break;

    default:
        break;
    }
}

void Window::clear(SDL_Color color)
{
    /*Set the color to fill the screen*/
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    /* Fill the screen with the color selected*/
    SDL_RenderClear(renderer);
}

void Window::present()
{
    SDL_RenderPresent(this->renderer);
}

bool Window::isWindowClosed()
{
    return this->closed;
}

const int Window::getHeight()
{
    return screenHeight;
}

const int Window::getWidth()
{
    return screenWidth;
}