#include<iostream>

int main()
{
	int i1 = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2; 
	int i2 = (((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2); 
	std::cout << i1 << " " << i2 << std::endl; 
	return 0;
}

