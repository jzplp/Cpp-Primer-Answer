#include <iostream>
#include "Person.h"

int main()
{
	Person p1;
	Person p2("1");
	Person p3("1", "2");
	Person p4(std::cin);
	
	print(std::cout, p1) << std::endl;
	print(std::cout, p2) << std::endl; 
	print(std::cout, p3) << std::endl; 
	print(std::cout, p4) << std::endl; 
	return 0;
} 

