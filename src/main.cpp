#include <iostream>
#include "RenderWindow.hpp"
#include "screens/DummyScreen.hpp"

int main(int argc, char** argv)
{
	RenderWindow* window;
	DummyScreen* dScreen;
	try 
	{
		window = new RenderWindow(800, 800);
		dScreen = new DummyScreen(window->renderer, 100, 100, 600, 600);
	}
	catch (const std::runtime_error& e) 
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}

	window->AddScreen(dScreen);
	window->Run();

	return 0;
}