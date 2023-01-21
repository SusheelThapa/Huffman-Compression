#pragma once

//Include headers
#include <SDL2/SDL.h>
#include <stdio.h>

//Macros
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

//Function prototypes
bool init();
void close();

//Global Variables
extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;