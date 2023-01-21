#include "window.hpp"

int main(int argc, char *argv[])
{

	Window window("Huffman Visualizer");

	while (!window.isWindowClosed())
	{
		window.handleEvent();

		window.clear({24, 100, 200, 150});

		window.present();
	}
	
	return 0;
}