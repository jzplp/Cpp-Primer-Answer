#include<iostream>

void fun(int i)
{
	auto fun1 = [i](int j) { return i+j; };
	std::cout << fun1(2) << std::endl;
}

int main()
{
	fun(1);
	return 0;
}


