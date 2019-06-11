#include <iostream>
#include "Screen.h"

int main()
{
	Window_mgr w;
	w.showScreen(std::cout, 0);
	w.clear(0);
	std::cout << "--" << std::endl;
	w.showScreen(std::cout, 0); 
	return 0;
} 

