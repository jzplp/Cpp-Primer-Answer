#include <iostream>
#include "Screen.h"

int main()
{
	Window_mgr<24, 80> w;
	Screen<24, 80> s('1');
	std::cout << s.size() << std::endl; 
	std::size_t i = w.addScreen(s);
	std::cout << i << std::endl;
	w.showScreen(std::cout, i);
	std::cin >> s;
	std::cout << s;
	return 0;
} 
