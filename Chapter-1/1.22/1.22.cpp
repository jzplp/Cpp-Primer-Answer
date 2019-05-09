#include<iostream>
#include"Sales_item.h"

int main()
{
	Sales_item book1, book2;
	if(!(std::cin >> book1))
		return 0;
	while(std::cin >> book2)
	{
		book1 += book2; 
	}
	std::cout << book1 << std::endl;
	return 0;
} 
