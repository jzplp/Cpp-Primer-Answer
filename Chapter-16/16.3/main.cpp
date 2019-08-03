#include<iostream>
#include "Sales_data.h"

template <typename T>
int compare(const T & v1, const T & v2)
{
	if(v1 < v2)
		return -1;
	if(v2 < v1)
		return 1;
	return 0;
}

int main()
{
	Sales_data a("123",10, 20), b("123",10, 30);
	
	std::cout << compare(a,b) << std::endl;
	return 0;
}
