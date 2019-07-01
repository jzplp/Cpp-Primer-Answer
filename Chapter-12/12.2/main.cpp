#include<iostream>
#include "StrBlob.h"

int main()
{
	StrBlob b1({"1","2","3"});
	const StrBlob b2({"1","2","3"});
	std::cout << b1.size() << " " << b2.size() << std::endl;
	 
	while(!b1.empty())
	{
		b1.front() = "123";
		std::cout << b1.front() << " ";
		b1.pop_back();
	}
	std::cout << std::endl;
	std::cout << b2.front() << " " << b2.back() << std::endl;
	
	return 0;
} 




