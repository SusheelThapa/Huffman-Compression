#include "huffman.hpp"

int main(int argc, char *argv[])
{

	Huffman a;

	/*Running the app till window is not closed*/
	while (!a.window.isWindowClosed())
	{
		/*Handling the events*/
		a.handleEvent();

		/*Clear the window with provide color*/
		a.window.clear({0, 0, 0, 0});

		/*Render the button in the window*/
		a.randomize.render(a.window);
		a.count.render(a.window);

		/*Updating the window*/
		a.window.present();
	}

	return 0;
}