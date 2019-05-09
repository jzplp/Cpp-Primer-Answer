#include<iostream>
#include"Sales_item.h"

int main()
{
	Sales_item book1, book2;
	int num = 0;
	if(!(std::cin >> book1))
		return 0;
	num++;
	while(std::cin >> book2)
	{
		if(book1.isbn() == book2.isbn())
		{
			num++;
			book1 += book2; 
		}
		else
		{
			std::cout << book1 << " num=" << num << std::endl;
			num = 1;
			book1 = book2;
		}
	}
	std::cout << book1 << " num=" << num << std::endl;
	return 0;
} 
