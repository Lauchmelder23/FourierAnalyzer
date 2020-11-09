#include <iostream>
#include "RenderWindow.hpp"
#include "screens/PlotScreen.hpp"
#include "screens/DummyScreen.hpp"
#include "Signal.hpp"

int main(int argc, char** argv)
{
	Signal sig;

	RenderWindow* window;
	try 
	{
		window = new RenderWindow(800, 800);
		window->AddScreen(new DummyScreen(window->renderer, 0, 0, 800, 800));
		window->AddScreen(new PlotScreen(window->renderer, &sig, 50, 50, 700, 300, 0, -1.5f, 10, 1.5f));
	}
	catch (const std::runtime_error& e) 
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}

	window->Run();

	return 0;
}