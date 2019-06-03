#include<iostream>
#include"Chapter6.h"

int main()
{
	int i;
	while (std::cin >> i)
		std::cout << fact(i) << std::endl;
	return 0;
}
