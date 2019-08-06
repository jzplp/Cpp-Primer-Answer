#include<iostream>
#include<memory>
#include "DebugDelete.h"

int main()
{
	std::unique_ptr<int, DebugDelete> u1(new int(3), DebugDelete());
	std::cout << *u1 << std::endl;
	u1.reset();
	std::unique_ptr<double, DebugDelete> u2(new double(3.0), DebugDelete());
	std::cout << *u2 << std::endl;
	u2.reset();
	
	int * i = new int(4);
	DebugDelete()(i);
	
	return 0;
}









