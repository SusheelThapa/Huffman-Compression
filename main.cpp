#include "window.hpp"
#include "texture.hpp"
#include "button.hpp"

int main(int argc, char *argv[])
{

	Window window("Huffman Visualizer");
	Button randomize, count;

	randomize.setRenderCoordinate(10, 20);

	count.setRenderCoordinate(200, 20);

	randomize.setText("Randomize");
	count.setText("Count");

	randomize.setBackgroundColor({0, 0, 255, 255});
	randomize.setTextColor({255, 255, 255, 255});

	while (!window.isWindowClosed())
	{
		window.handleEvent();

		window.clear({0, 0, 0, 0});

		randomize.render(window);
		count.render(window);

		window.present();
	}
	return 0;
}