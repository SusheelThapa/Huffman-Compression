#include "window.hpp"
#include "texture.hpp"

int main(int argc, char *argv[])
{

	Window window("Huffman Visualizer");
	Texture windowBackground;

	std::string background = "resources/background.png";
	windowBackground.loadFromFile(window, background);

	while (!window.isWindowClosed())
	{
		window.handleEvent();

		window.clear({24, 100, 200, 150});

		SDL_Rect display = window.camera;

		windowBackground.render(window, 0, 0, &display);
		window.present();
	}

	return 0;
}