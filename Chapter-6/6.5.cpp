#include<iostream>

int abs (int x)
{
	if (x < 0)
		return -x;
	return x;
}

int main()
{
	int i;
	while (std::cin >> i)
		std::cout << abs(i) << std::endl;
	return 0;
}

