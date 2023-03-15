#include "huffman.hpp"

int main(int argc, char *argv[])
{

	Huffman a(20);
	a.pq.display();

	/*Running the app till window is not closed*/
	while (!a.window.isWindowClosed())
	{
		/*Handling the events*/
		a.handleEvent();

		/*Clear the window with provide color*/
		a.window.clear({0, 0, 0, 0});

		a.randomizeButton.render(a.window, 400, 71);

		// a.randomizeBox.render(a.window);
		a.randomizeText.render(a.window);

		a.countButton.render(a.window, 1000, 71);

		// Appears after countButton is pressed
		a.countBox.render(a.window);

		a.renderHuffmanTree();

		/*Updating the window*/
		a.window.present();

		a.randomizeText.free();
	}

	std::cout << "Depth of the tree is " << a.depthOfHuffmanTree << std::endl;

	return 0;
}