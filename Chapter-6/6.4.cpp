#include<iostream>

int fact (int x)
{
	int value = 1;
	for ( ; x > 1; --x)
		value *= x;
	return value; 
}

int main()
{
	int i;
	while (std::cin >> i)
		std::cout << fact(i) << std::endl;
	return 0;
}

