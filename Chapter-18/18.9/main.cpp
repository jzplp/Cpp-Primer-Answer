#include<iostream>
#include<vector>
#include<string>
#include "Sales_data.h"

int main()
{
	Sales_data item1, item2, sum;
	while(std::cin >> item1 >> item2)
	{
		try
		{
			sum = item1 + item2;
			std::cout << sum << std::endl; 
		}
		catch(const isbn_mismatch &e)
		{
			std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << std::endl;
		}
	}
	return 0;
} 


