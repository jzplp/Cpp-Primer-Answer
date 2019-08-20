#include<iostream>
#include<vector>
#include<string>
#include "Sales_data.h"

int main()
{
	Sales_data item1, item2, sum;
	while(std::cin >> item1 >> item2)
	{
		sum = item1 + item2;
		std::cout << sum << std::endl; 
	}
	return 0;
} 

