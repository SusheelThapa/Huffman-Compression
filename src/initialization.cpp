#include "headers\header.hpp"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

//Initialization function Definitions
bool init()
{

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	else
	{
		//Create Window
		gWindow = SDL_CreateWindow("Huffman Compression", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created. SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize Renderer color
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xff);
			}
		}
	}
	return success;
}

void close()
{
	//Destroy renderer
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

    //Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL Subsystem
	SDL_Quit();
}
