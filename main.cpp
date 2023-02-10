#include "huffman.hpp"

int main(int argc, char *argv[])
{

	Huffman a;

	while (!a.window.isWindowClosed())
	{
		a.handleEvent();

		a.randomize.render(a.window);
		a.count.render(a.window);

		a.window.present();
	}
	return 0;
}