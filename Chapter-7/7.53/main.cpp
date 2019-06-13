#include<iostream>
#include "Debug.h"

int main()
{
	constexpr Debug io_sub(false, true, false);
	if(io_sub.any())
		std::cerr << "print error" << std::endl;
	constexpr Debug prod(false);
	if(prod.any())
		std::cerr << "print error" << std::endl; 
	
	return 0;
} 





