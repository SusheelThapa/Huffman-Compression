#include "huffman.hpp"

int main(int argc, char *argv[])
{

	Huffman a(1000);

	/*Running the app till window is not closed*/
	while (!a.window.isWindowClosed())
	{
		/*Handling the events*/
		a.handleEvent();

		/*Clear the window with provide color*/
		a.window.clear({0, 0, 0, 0});

		a.render();

		/*Updating the window*/
		a.window.present();
	}

	std::cout << "Original size is: " << a.originalSize << " Compressed size is: " << a.compressedSize << std::endl;
	return 0;
}