#include "huffman.hpp"

int main(int argc, char *argv[])
{

	Huffman huffman(1000);

	/*Running the app till window is not closed*/
	while (!huffman.window.isWindowClosed())
	{
		/*Handling the events*/
		huffman.handleEvent();

		/*Clear the window with provide color*/
		huffman.window.clear({0, 0, 0, 0});

		huffman.render();

		/*Updating the window*/
		huffman.window.present();
	}

	std::cout << "Original size is: " << huffman.originalSize << " Compressed size is: " << huffman.compressedSize << std::endl;
	return 0;
}