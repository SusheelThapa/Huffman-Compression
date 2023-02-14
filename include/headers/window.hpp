#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

class Window
{

private:
    std::string title;

    static const int screenWidth = 1280;

    static const int screenHeight = 720;

    bool closed = false;

    bool leftMouseButtonDown = false;

    SDL_Window *window = nullptr;

    SDL_Event e;

    SDL_Point startPan = {0,0};

    SDL_Point mousePos;

public:
    SDL_Renderer *renderer = nullptr;

    SDL_Point offsetCords = {0,0};

    static const int worldWidth = 2560;

    static const int worldHeight = 1600;

private:
    bool init();

public:
    Window();
    Window(std::string);

    ~Window();

    void handleEvent();

    void clear(SDL_Color color);

    void present();

    bool isWindowClosed();

    static const int getWidth();

    static const int getHeight();
};