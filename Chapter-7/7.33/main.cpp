#include <iostream>
#include "Screen.h"

int main()
{
	Window_mgr w;
	Screen s(24, 80, '1');
	std::cout << s.size() << std::endl; 
	Window_mgr::SIndex i = w.addScreen(s);
	w.showScreen(std::cout, 1);
	return 0;
}