#include<iostream>
int main()
{
	int i1 = 1, i2 = 2;
	int * p1 = &i1;
	// 更改指针的值 
	p1 = &i2;
	// 更改指针所指对象的值
	*p1 = 3;
	std::cout << i1 << " " << i2 << std::endl; 
	return 0;
}
