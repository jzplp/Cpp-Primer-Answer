#include<iostream>
#include<initializer_list>

int sum(std::initializer_list<int> l)
{
	int m = 0;
	for(int i : l)
		m += i;
	return m;
}

int main()
{
	std::cout << sum({1,2,3,4,5}) << std::endl;
	return 0;
}


