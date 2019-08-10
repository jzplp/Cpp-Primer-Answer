#include <iostream>
#include <string>
#include<unordered_set>
#include "Sales_data.h"

int main()
{
	std::unordered_multiset<Sales_data> SDset;
	SDset.emplace("123", 4, 5);
	SDset.emplace("234", 5, 6);
	for(std::unordered_multiset<Sales_data>::iterator ip = SDset.begin(); ip != SDset.end(); ++ip)
		std::cout << *ip << std::endl;
	return 0;
} 

