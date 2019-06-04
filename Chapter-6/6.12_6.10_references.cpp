#include<iostream>

void change(int &p1, int &p2)
{
	int i = p1;
	p1 = p2;
	p2 = i;
}

int main()
{
	int i = 1, j = 2;
	change(i, j);
	std::cout << i << " " << j << std::endl;
	return 0;
} 

