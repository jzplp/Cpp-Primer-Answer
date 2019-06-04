#include<iostream>

void reset(int &r)
{
	r = 0;
}

int main()
{
	int i = 1;
	reset(i);
	std::cout << i << std::endl;
	return 0;
} 
