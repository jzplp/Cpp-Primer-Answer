#include <iostream>
#include "Screen.h"

int main()
{
	Screen s1;
	Screen s2(24, 80);
	Screen s3(24, 80, 'q');
	
	std::cout << '|' << s1.get() << '|' << std::endl;
	std::cout << '|' << s2.get(1,1) << '|' << std::endl;
	std::cout << '|' << s3.get(1,1) << '|' << std::endl;
	return 0;
} 

