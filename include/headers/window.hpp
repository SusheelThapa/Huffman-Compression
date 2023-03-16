#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include <cmath>

class Window
{

private:
    /*Private Variables*/
    std::string title;

    static const int screenWidth = 1280;

    static const int screenHeight = 720;

    bool closed = false;

    bool leftMouseButtonDown = false;

    SDL_Window *window = nullptr;

    SDL_Point startPan = {0, 0};

    SDL_Point mousePos;

public:
    /*Public Variables*/
    SDL_Renderer *renderer = nullptr;

    SDL_Point offsetCords = {0, 0};

    static const int worldWidth = 2560 * 5;

    static const int worldHeight = 1600 * 2;

private:
    /*Private Function*/
    bool init();

public:
    /*Public Function*/
    Window();
    Window(std::string);

    ~Window();

    void handleEvent(SDL_Event e);

    void clear(SDL_Color color);

    void present();

    bool isWindowClosed();

    static const int getWidth();

    static const int getHeight();
};