#include <iostream>
#include "RenderWindow.hpp"
#include "screens/PlotScreen.hpp"
#include "screens/DummyScreen.hpp"
#include "Signal.hpp"

int main(int argc, char** argv)
{
	Signal sig;

	RenderWindow* window;
	DummyScreen* ds;
	PlotScreen* ps;
	try 
	{
		window = new RenderWindow(800, 800);

		ds = new DummyScreen(window->renderer, 0, 0, 800, 800);
		ps = new PlotScreen(window->renderer, &sig, 50, 50, 700, 300, 0, -1.5f, 10, 1.5f);

		window->AddScreen(ds);
		window->AddScreen(ps);
	}
	catch (const std::runtime_error& e) 
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}

	window->Run();

	window->RemoveScreen(ps);
	window->RemoveScreen(ds);

	delete ps;
	delete ds;
	delete window;

	return 0;
}