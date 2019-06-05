#include<iostream>

void print(const int *pa, int len)
{
	for(int i = 0; i < len; ++i)
	{
		std::cout << *pa++ << " ";
	}
	std::cout << std::endl; 
} 

int main()
{
	int i = 0, j[2] = {0, 1};
	print(&i, 1);
	print(j, 2);
	
	return 0;
} 

