#include <iostream>
#include "RenderWindow.hpp"

int main(int argc, char** argv)
{
	RenderWindow* window;
	try 
	{
		window = new RenderWindow(800, 800);
	}
	catch (const std::runtime_error& e) 
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}

	window->Run();

	return 0;
}