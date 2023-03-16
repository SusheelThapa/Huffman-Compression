#include "huffman.hpp"

int main(int argc, char *argv[])
{

	Huffman a(3000);
	a.pq.display();

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

	std::cout << "Depth of the tree is " << a.depthOfHuffmanTree << std::endl;

	return 0;
}