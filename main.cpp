#include "huffman.hpp"

int main(int argc, char *argv[])
{
	Huffman a(30);
	a.pq.display();
	a.createHuffmanTree();
	a.pq.display();

	/*Running the app till window is not closed*/
	while (!a.window.isWindowClosed())
	{
		/*Handling the events*/
		a.handleEvent();

		/*Clear the window with provide color*/
		a.window.clear({0, 0, 0, 0});

		a.randomize.render(a.window, 550 - a.window.offsetCords.x, 100 - a.window.offsetCords.y);

		a.count.render(a.window, 1280 - a.window.offsetCords.x, 100 - a.window.offsetCords.y);

		/*Updating the window*/
		a.window.present();
	}

	return 0;
}