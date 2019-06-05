#include<iostream>
int comp(int a,const int *bp)
{
	if (a > *bp)
		return a;
	else
		return *bp;
} 

int main()
{
	int a = 1, b = 2;
	std::cout << comp(a, &b) << std::endl;
	
	return 0;
} 

