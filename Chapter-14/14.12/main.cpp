#include <iostream>
#include <string>
#include "Tree.h"

int main()
{
	Tree t1(1), t2(2), t3;
	std::cin >> t3;
	std::cout << t3 << std::endl;
	std::cout << (t1 == t2) << std::endl;
	std::cout << t1 << " " << t2 << std::endl;
	return 0;
} 

