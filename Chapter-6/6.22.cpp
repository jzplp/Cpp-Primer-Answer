#include<iostream>
void change(int **pa, int **pb)
{
	int *p = *pa;
	*pa = *pb;
	*pb = p; 
} 

int main()
{
	int a = 1, b = 2;
	int *pa = &a, *pb = &b;
	change(&pa, &pb);
	std::cout << *pa << " " << *pb << std::endl;
	
	return 0;
} 

