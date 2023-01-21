#include "headers/header.hpp"

int main(int argc, char* argv[])
{
	//Starts up SDL and create window
	if (!init()) {
		printf("Failed to initialize!");
	}
	else
	{

        //Sample Code to see if everything works
        SDL_RenderClear(gRenderer);
        SDL_Rect fillRect = {10, 10, 100, 100};
        SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
        SDL_RenderFillRect(gRenderer, &fillRect);
        SDL_RenderPresent(gRenderer);

		//Quit when the user wants
		SDL_Event e;
		
		bool quit = false;
		while (!quit)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT) {
					quit = true;
				}

				if (e.key.keysym.sym == SDL_SCANCODE_ESCAPE) {
					quit = true;
				}
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}