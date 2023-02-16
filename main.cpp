#include "huffman.hpp"

int main(int argc, char *argv[])
{
	Huffman a;

	while (!a.window.isWindowClosed())
	{
		a.handleEvent();

		a.window.clear({0, 0, 0, 0});

		a.randomize.render(a.window, 550 - a.window.offsetCords.x, 100 - a.window.offsetCords.y);

		a.count.render(a.window, 1280 - a.window.offsetCords.x, 100 - a.window.offsetCords.y);

		a.window.present();
	}
	return 0;
}